#include <iostream>
#include "pugixml.hpp"
#include <map>
#include <vector>
#include "Data.h"
#include <algorithm>
#include <math.h>


using namespace std;

double count_dist(double lat1, double long1, double lat2, double long2) {
    const int EARTH_RADIUS = 6372795;
    lat1 = lat1 * M_PI / 180;
    long1 = long1 * M_PI / 180;
    lat2 = lat2 * M_PI / 180;
    long2 = long2 * M_PI / 180;
    double delta = long2 - long1;
    double tmp1 = cos(lat1) * cos(lat2) * pow(sin(delta / 2), 2);
    double tmp2 = pow((lat2 - lat1) / 2, 2);
    return 2 * asin(sqrt(tmp1 + tmp2)) * EARTH_RADIUS;
}

int main() {
    system("chcp 65001");
    Data dict;
    pugi::xml_document doc;
    //Task 1
    cout << "Task #1:" << endl;
    dict.make_routes("Автобус", doc);
    int route_length = -1;
    string route_number;
    dict.find_max_route(route_length, route_number);
    cout << "Bus: Route number - " << route_number << ", number of stops - " << route_length << endl;
    dict.clear();
    route_length = -1;
    dict.make_routes("Троллейбус",doc);
    dict.find_max_route(route_length, route_number);
    cout << "Trolleybus: Route number - " << route_number << ", number of stops - " << route_length << endl;
    dict.clear();
    route_length = -1;
    dict.make_routes("Трамвай", doc);
    dict.find_max_route(route_length, route_number);
    cout << "Tram: Route number - " << route_number << ", number of stops - " << route_length << endl;
    //Task 2
    return 0;
}
