#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// The number of cities that needed to be defined 
enum Cities { RIVERSIDE, MORENO_VALLEY, PERRIS, HEMET, NUM_CITIES };

// The Distance matrix representing distances between cities
int distances[NUM_CITIES][NUM_CITIES] = {
    {0, 10, 15, 20},   // From Riverside
    {10, 0, 35, 25},   // From Moreno Valley
    {15, 35, 0, 30},   // From Perris
    {20, 25, 30, 0}    // From Hemet
};

// The Function to calculate the total distance for a given route for each city 
int calculateDistance(vector<int> route) {
    int totalDistance = 0;

    // Add the distances between consecutive cities in the route
    for (size_t i = 0; i < route.size() - 1; i++) {
        totalDistance += distances[route[i]][route[i + 1]];
    }

    // Return to the starting city which was Riverside
    totalDistance += distances[route.back()][route[0]];
    return totalDistance;
}

// Function to find the shortest and most effective route
void findShortestRoute() {
    vector<int> cities = {MORENO_VALLEY, PERRIS, HEMET}; // Excluded Riverside, as it's the start and end of this route
    vector<int> bestRoute;
    int shortestDistance = INT_MAX;

    // Generated all permutations of the cities
    do {
        // Add Riverside as the starting and ending point
        vector<int> route = {RIVERSIDE};
        route.insert(route.end(), cities.begin(), cities.end());
        route.push_back(RIVERSIDE);

        // Calculate the total distance for the current route
        int currentDistance = calculateDistance(route);

        // Update shortest distance and best route if applicable
        if (currentDistance < shortestDistance) {
            shortestDistance = currentDistance;
            bestRoute = route;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    // Output of the results
    cout << "Shortest route: ";
    for (int city : bestRoute) {
        switch (city) {
            case RIVERSIDE: cout << "Riverside -> "; break;
            case MORENO_VALLEY: cout << "Moreno Valley -> "; break;
            case PERRIS: cout << "Perris -> "; break;
            case HEMET: cout << "Hemet -> "; break;
        }
    }
    cout << "Riverside" << endl; // Loops back to the start 

    cout << "Shortest distance: " << shortestDistance << " units" << endl;
}

int main() {
    cout << "Calculating the shortest and most effective route...\n" << endl;
    findShortestRoute();
    return 0;
}
