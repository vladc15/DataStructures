#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <chrono>

#include "Segment.h"
#include "Event.h"
#include "AVL.h"

std::ifstream fin("input.in");
std::ofstream fout("output.out");


int main() {
    int n;

    std::vector<Segment> segments;
    std::vector<Event> events;

    fin >> n;
    for (int i=0; i<n; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;

        Segment s(x1, y1, x2, y2); s.setIndex(i);
        segments.push_back(s);

        Event e1(x1, y1, i, 0); Event e2(x2, y2, i, 1);
        events.push_back(e1); events.push_back(e2);
    }

    std::sort(events.begin(), events.end());


    std::map< std::pair<int, int>, std::pair<double, double> > intersectionsMAP;

    std::map<Event, int> activeEventsMAP;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<2*n; i++) {

        Event current = events[i];
        int ind = current.getIndex();

        if (current.getType() == 0) { /// capat stanga
            auto next = activeEventsMAP.lower_bound(current);
            auto prev = next;
            if (prev != activeEventsMAP.begin())
                prev--;
            else
                prev = activeEventsMAP.end();

            if (next != activeEventsMAP.end() && Intersects(segments[next->first.getIndex()], segments[ind]))  /// punct
                intersectionsMAP[std::make_pair(ind, next->first.getIndex())] = getIntersection(segments[ind], segments[next->first.getIndex()]);

            if (prev != activeEventsMAP.end() && Intersects(segments[prev->first.getIndex()], segments[ind]))  /// punct
                intersectionsMAP[std::make_pair(prev->first.getIndex(), ind )] = getIntersection(segments[ind], segments[prev->first.getIndex()]);


            activeEventsMAP[current] = ind;

        }
        else {

            auto it = activeEventsMAP.find(Event(segments[ind].getX1(), segments[ind].getY1(), ind, 0));

            auto next = ++it;
            auto prev = --it;
            if (prev != activeEventsMAP.begin())
                prev--;
            else
                prev = activeEventsMAP.end();

            if (next != activeEventsMAP.end() && prev != activeEventsMAP.end() && Intersects(segments[next->first.getIndex()], segments[prev->first.getIndex()]))  /// punct
                intersectionsMAP[std::make_pair(prev->first.getIndex(), next->first.getIndex())] = getIntersection(segments[next->first.getIndex()], segments[prev->first.getIndex()]);

            activeEventsMAP.erase(it);

        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "MAP: " << duration.count() << " ms" << "\n";

    int ok1 = 0;
    for (auto it : intersectionsMAP) {
        fout << it.first.first << " " << it.first.second << " " << it.second.first << " " << it.second.second << "\n";
        ok1 = 1;
    }
    if (!ok1)
        fout << "Nu exista intersectii\n";



    std::map< std::pair<int, int>, std::pair<double, double> > intersectionsAVL;

    AVL<Event> activeEventsAVL;

    start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<2*n; i++) {

        Event current = events[i];
        int ind = current.getIndex();

        if (current.getType() == 0) { /// capat stanga
            auto next = activeEventsAVL.lower_bound(current);

            auto prev = next;
            if (prev == activeEventsAVL.begin())
                prev = nullptr;
            else
                if (prev == nullptr)
                    prev = activeEventsAVL.getMaximumNode();
                else
                    prev = activeEventsAVL.getPreviousNode(prev->getKey());


            if (next != nullptr && Intersects(segments[next->getKey().getIndex()], segments[ind]))  /// punct
                intersectionsAVL[std::make_pair(ind, next->getKey().getIndex())] = getIntersection(segments[ind], segments[next->getKey().getIndex()]);

            if (prev != nullptr && Intersects(segments[prev->getKey().getIndex()], segments[ind]))  /// punct
                intersectionsAVL[std::make_pair(prev->getKey().getIndex(), ind )] = getIntersection(segments[ind], segments[prev->getKey().getIndex()]);


            activeEventsAVL.insert(current);

        }
        else {

            auto it = activeEventsAVL.find(Event(segments[ind].getX1(), segments[ind].getY1(), ind, 0));

            auto next = activeEventsAVL.lower_bound(it->getKey());

            auto prev = next;

            if (prev == activeEventsAVL.begin())
                prev = nullptr;
            else
                if (prev == nullptr)
                    prev = activeEventsAVL.getMaximumNode();
                else
                    prev = activeEventsAVL.getPreviousNode(prev->getKey());

            if (next != nullptr && prev != nullptr && Intersects(segments[next->getKey().getIndex()], segments[prev->getKey().getIndex()]))  /// punct
                intersectionsAVL[std::make_pair(prev->getKey().getIndex(), next->getKey().getIndex())] = getIntersection(segments[next->getKey().getIndex()], segments[prev->getKey().getIndex()]);

            activeEventsAVL.erase(it->getKey());
        }
    }

    stop = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "AVL: " << duration.count() << " ms" << "\n";



    int ok = 0;
    for (auto it : intersectionsAVL) {
        fout << it.first.first << " " << it.first.second << " " << it.second.first << " " << it.second.second << "\n";
        ok = 1;
    }
    if (!ok)
        fout << "Nu exista intersectii";

    /**

    5
    1 5 4 5
    2 5 10 1
    3 2 10 3
    6 4 9 4
    7 1 8 1

    0 1 2 5
    2 1 6.88889 2.55556

    2
    1 1 2 2
    -1 0 0 0

    Nu exista intersectii

     20
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
65 66 67 68 69 70 71 72
73 74 75 76 77 78 79 80
81 82 83 84 85 86 87 88
89 90 91 92 93 94 95 96
97 98 99 100 101 102 103 104
105 106 107 108 109 110 111 112
113 114 115 116 117 118 119 120
121 122 123 124 125 126 127 128
129 130 131 132 133 134 135 136
137 138 139 140 141 142 143 144
145 146 147 148 149 150 151 152

     Nu exista intersectii

     */

    return 0;
}

