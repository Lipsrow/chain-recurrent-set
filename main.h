#include <iostream>
#include <forward_list>
#include <map>
#include <set>
#include <vector>
using namespace std;

namespace main {
    class Area;
    const int ROW = 2;
    const int COLUMN = 2;
    double a = 0;
    double b = -0.8;
    const int n = 6;
    const int m = 6;
    int MAX_ITER = 12;
    double xmin = -1.5;
    double xmax = 1.5;
    double ymin = -1.5;
    double ymax = 1.5;
    const long long MAX_SIZE = 1 + ROW * COLUMN * (long long)pow(4, MAX_ITER - 1);
    int amount = 0;



    class Point {
    public:
        double x, y;
        Point(double x = 0, double y = 0) {
            this->x = x;
            this->y = y;
        }

    };

    Point display_point(Point p) {
        return Point(p.x * p.x - p.y * p.y + a, 2 * p.x * p.y + b);
    }


    class Area {
    public:
        Point A, B;
        double hx, hy;
        int number;
    public:
        Area() {}
        Area(Point A, Point B, int n) {
            this->A = A;
            this->B = B;
            this->hx = B.x - A.x;
            this->hy = A.y - B.y;
            this->number = n;
        }
    };

    forward_list<Area> areas(ROW * COLUMN);
    map<int, set<int>> graph;
    vector<bool> deleted(MAX_SIZE);
    Area S(Point(xmin, ymax), Point(xmax, ymin), 1);

    class TarjanSCC {
    public:
        int index = 0;
        vector<int> st;
        map<int, int> ids;
        map<int, int> lowlink;
        set<int> sccs;
        TarjanSCC(map<int, set<int>>& graph) {
            for (const auto& pair : graph) {
                int node = pair.first;
                if (!lowlink.count(node)) {
                    this->tarjan(node);
                }
            }
        }
        void tarjan(int v) {
            this->ids[v] = this->index;
            this->lowlink[v] = this->index;
            ++index;
            this->st.push_back(v);
            for (int neighbour : graph[v]) {
                if (!ids.count(neighbour)) {
                    this->tarjan(neighbour);
                    this->lowlink[v] = min(this->lowlink[v], this->lowlink[neighbour]);
                }
                else if (find(st.begin(), st.end(), neighbour) != st.end()) {
                    this->lowlink[v] = min(this->lowlink[v], this->ids[neighbour]);
                }
            }
            if (this->ids[v] == this->lowlink[v]) {
                vector<int> scc;
                while (true)
                {
                    int node = *(st.end() - 1);
                    st.pop_back();
                    scc.push_back(node);
                    if (node == v) {
                        break;
                    }
                }
                if (scc.size() > 1) {
                    for (auto el : scc) {
                        sccs.insert(el);
                    }
                }
            }
        }
    };


    void get_points(Area& s, vector<Point>& points)
    {
        vector<double> xs(n);
        vector<double> ys(m);
        for (int i = 0; i < n; i++) {
            xs[i] = s.A.x + i * s.hx / (n - 1);
        }
        for (int i = 0; i < m; i++) {
            ys[i] = s.A.y - i * s.hy / (m - 1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back(display_point(Point(xs[j], ys[i])));
            }
        }
    }
    void split_first(Area& s, forward_list<Area>& areas) {
        forward_list<Area> new_areas(ROW * COLUMN);
        areas = new_areas;
        vector<double> xs(ROW + 1);
        vector<double> ys(COLUMN + 1);
        for (int i = 0; i < ROW + 1; i++) {
            xs[i] = s.A.x + i * s.hx / ROW;
        }
        for (int i = 0; i < COLUMN + 1; i++) {
            ys[i] = s.A.y - i * s.hy / COLUMN;
        }
        auto it = areas.begin();
        for (int i = 0; i < COLUMN; i++) {
            for (int j = 0; j < ROW; j++) {
                *it = Area(Point(xs[j], ys[i]), Point(xs[j + 1], ys[i + 1]), i * ROW + j + 1);
                ++it;
            }
        }
    }
    void get_new_numbers(int number, int iter, int* new_numbers) {
        int in_row_before = ROW * (int)pow(2, iter - 1);
        int row = (int)((number - 1) / in_row_before);
        int col = (number - 1) % in_row_before;
        int n1 = row * 4 * in_row_before + col * 2 + 1;
        int in_row_after = in_row_before * 2;
        int n2 = n1 + 1;
        int n3 = n1 + in_row_after;
        int n4 = n3 + 1;
        new_numbers[0] = n1;
        new_numbers[1] = n2;
        new_numbers[2] = n3;
        new_numbers[3] = n4;
    }

    void split_four(Area& s, vector<Area>& new_areas, int iter) {
        double x0 = (s.A.x + s.B.x) / 2;
        double y0 = (s.A.y + s.B.y) / 2;
        int new_numbers[4];
        get_new_numbers(s.number, iter, new_numbers);
        Area A1(Point(s.A.x, s.A.y), Point(x0, y0), new_numbers[0]);
        Area A2(Point(x0, s.A.y), Point(s.B.x, y0), new_numbers[1]);
        Area A3(Point(s.A.x, y0), Point(x0, s.B.y), new_numbers[2]);
        Area A4(Point(x0, y0), Point(s.B.x, s.B.y), new_numbers[3]);
        deleted[new_numbers[0]] = 0;
        deleted[new_numbers[1]] = 0;
        deleted[new_numbers[2]] = 0;
        deleted[new_numbers[3]] = 0;
        new_areas[0] = A4;
        new_areas[1] = A3;
        new_areas[2] = A2;
        new_areas[3] = A1;
    }

    void update_deleted(int iter) {
        auto new_deleted = deleted;
        for (int i = 1; i < ROW * COLUMN * (int)pow(4, iter - 1); i++) {
            if (deleted[i] == 1) {
                int new_numbers[4];
                get_new_numbers(i, iter, new_numbers);
                new_deleted[new_numbers[0]] = 1;
                new_deleted[new_numbers[1]] = 1;
                new_deleted[new_numbers[2]] = 1;
                new_deleted[new_numbers[3]] = 1;
            }
        }
        deleted = new_deleted;
    }

    void symbolic_display(int iter)
    {
        graph.clear();
        update_deleted(iter);
        if (iter == 0) {
            split_first(S, areas);
        }
        else {
            forward_list<Area> new_areas = { Area() };
            vector<Area> splitted(4);
            auto new_it = new_areas.begin();
            for (auto it = areas.begin(); it != areas.end(); ++it) {
                split_four(*it, splitted, iter);
                for (auto& area : splitted) {
                    new_it = new_areas.insert_after(new_it, area);
                }
            }
            new_areas.pop_front();
            areas = new_areas;
        }
        graph.clear();
        double in_row = ROW * pow(2, iter);
        double in_col = COLUMN * pow(2, iter);
        double sizex = S.hx / in_row;
        double sizey = S.hy / in_col;
        for (auto area : areas) {
            set<int> s;
            vector<Point> points;
            get_points(area, points);
            for (auto point : points) {
                if ((point.x < xmin) || (point.x > xmax) || (point.y > ymax)
                    || (point.y < ymin)) {
                    continue;
                }
                int num = (int)((S.A.y - point.y) / sizey) * in_row + (int)((point.x - S.A.x) / sizex) + 1;
                if (num > ROW * COLUMN * pow(4, iter)) {
                    continue;
                }
                if (!deleted[num]) {
                    s.insert(num);
                }
            }
            graph[area.number] = s;
        }
    }

    void update() {
        TarjanSCC t(graph);
        set<int> remained = t.sccs;
        amount = remained.size();
        forward_list<Area> new_areas(amount);
        auto new_it = new_areas.begin();
        for (auto it = areas.begin(); it != areas.end(); ++it) {
            if (remained.count((*it).number)) {
                *new_it = *it;
                ++new_it;
            }
            else {
                deleted[(*it).number] = 1;
            }
        }
        areas = new_areas;
    }

    void iterate(int K) {
        for (int i = 0; i < K; i++) {
            symbolic_display(i);
            update();
            cout << amount << endl;
        }
    }

    void iterate_more(int iter) {
        symbolic_display(iter - 1);
        update();
    }

}
