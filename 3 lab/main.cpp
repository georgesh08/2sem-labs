#include <iostream>
#include "pugixml.hpp"
#include "Data.h"
#include <algorithm>
using std::cout, std::endl;

int main() {
    system("chcp 65001");
    Data dict;
    pugi::xml_document doc;
    freopen("answers.txt", "w", stdout);
    //Task 1
    cout << "Task #1:" << endl;
    dict.make_routes("Автобус", doc, 1);
    int route_length = -1;
    string route_number;
    dict.find_max_route(route_length, route_number);
    cout << "Bus: Route number - " << route_number << ", number of stops - " << route_length << endl;
    route_length = -1;
    dict.make_routes("Троллейбус",doc, 1);
    dict.find_max_route(route_length, route_number);
    cout << "Trolleybus: Route number - " << route_number << ", number of stops - " << route_length << endl;
    route_length = -1;
    dict.make_routes("Трамвай", doc, 1);
    dict.find_max_route(route_length, route_number);
    cout << "Tram: Route number - " << route_number << ", number of stops - " << route_length << endl;
    //Task 2
    cout << endl << "Task #2:" << endl;
    dict.make_routes("Автобус", doc, 2);
    dict.count_max_route();
    dict.find_max("Bus");
    dict.make_routes("Троллейбус", doc, 2);
    dict.count_max_route();
    dict.find_max("Trolleybus");
    dict.make_routes("Трамвай", doc, 2);
    dict.count_max_route();
    dict.find_max("Tram");
    //Task 3
    cout << endl << "Task #3:" << endl;
    route_length = -1;
    dict.max_street_stops(doc);
    dict.find_max_route(route_length, route_number);
    cout << "Street name - " << route_number << ", number of stops - " << route_length << endl;
    return 0;
}
