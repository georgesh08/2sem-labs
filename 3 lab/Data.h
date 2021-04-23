#ifndef INC_3_LAB_DATA_H
#define INC_3_LAB_DATA_H

#include "pugixml.hpp"
#include <map>
#include <vector>
#include <cmath>

using namespace std;

class Data {
public:

    double count_dist(double lat1, double long1, double lat2, double long2) {
        const int EARTH_RADIUS = 6372795;
        lat1 = lat1 * M_PI / 180;
        long1 = long1 * M_PI / 180;
        lat2 = lat2 * M_PI / 180;
        long2 = long2 * M_PI / 180;
        double delta = long2 - long1;
        double tmp1 = cos(lat1) * cos(lat2) * pow(sin(delta / 2), 2);
        double tmp2 = pow((lat2 - lat1) / 2, 2);
        return 2 * asin(sqrt(tmp1 + tmp2)) * EARTH_RADIUS / 1000;
    }

    static vector<string> find_by_delimiter(const char delimiter, string a, const string &type) {
        vector<string> tmp;
        while (!a.empty()) {
            int x = a.find(delimiter);
            if (x == -1) {
                tmp.push_back(a);
                break;
            }
            tmp.push_back(a.substr(0, x));
            if (type == "route" || type == "coordinates")
                a.erase(0, x + 1);
            else
                a.erase(0, x + 2);
        }
        return tmp;
    }

    void find_max_route(int &length, string &name) {
        for (auto &item : this->dict) {
            if (item.second > length) {
                length = item.second;
                name = item.first;
            }
        }
    }

    void make_routes(string const &str, pugi::xml_document &doc, int task_number) {
        doc.load_file("data.xml");
        if (task_number != 2)
            this->dict.clear();
        else
            this->max_length.clear();
        for (pugi::xml_node node = doc.child("dataset").first_child(); node; node = node.next_sibling()) {
            string type_of_vehicle = node.child("type_of_vehicle").text().as_string();
            if (type_of_vehicle != str)
                continue;
            string routes = node.child("routes").text().as_string();
            vector<string> tmp;
            if (routes.find(',') != -1)
                tmp = find_by_delimiter(',', routes, "route");
            if (routes.find('.') != -1)
                tmp = find_by_delimiter('.', routes, "route");
            if (routes.find(',') == -1 && routes.find('.') == -1)
                tmp.push_back(routes);
            if (task_number != 2)
                for (auto &route : tmp) {
                    this->dict[route]++;
                }
            else {
                string coords = node.child("coordinates").text().as_string();
                vector<string> coordinates;
                coordinates = find_by_delimiter(',', coords, "coordinates");
                for (auto &route : tmp) {
                    this->max_length[route].push_back(
                            std::make_pair(std::stod(coordinates[0]), std::stod(coordinates[1])));
                }
            }
        }
    }

    void max_street_stops(pugi::xml_document &doc) {
        doc.load_file("data.xml");
        this->dict.clear();
        for (pugi::xml_node node = doc.child("dataset").first_child(); node; node = node.next_sibling()) {
            string streets = node.child("location").text().as_string();
            vector<string> tmp = find_by_delimiter(',', streets, "street");
            for (auto &street : tmp)
                this->dict[street]++;
        }
    }

    void count_max_route() {
        route_dist.clear();
        for (auto elem : max_length) {
            double res = 0;
            for (int i = 0; i < elem.second.size() - 1; ++i) {
                double min = 1e9;
                for (int j = i + 1; j < elem.second.size(); ++j) {
                    double tmp = count_dist(elem.second[i].first, elem.second[i].second, elem.second[j].first,
                                            elem.second[j].second);
                    if (tmp < min)
                        min = tmp;
                }
                res += min;
            }
            route_dist[elem.first] = res;
        }
    }

    void find_max(string type_of_vehicle) {
        double max = -1;
        string name;
        for (auto elem : route_dist)
            if (elem.second > max) {
                max = elem.second;
                name = elem.first;
            }
        cout <<  type_of_vehicle << ": Route number - " << name << ", distance - " << max/2 << endl;
    }

private:
    map<string, int> dict;
    map<string, double> route_dist;
    map<string, vector<std::pair<double, double>>> max_length;
};


#endif
