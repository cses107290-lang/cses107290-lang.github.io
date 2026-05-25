#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Optimize I/O speed
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    // Read the number of times liquid is poured
    if (!(cin >> n)) return 0;

    int w1, w2, h1, h2;
    // Read cup dimensions: bottom width w1, top width w2, bottom height h1, top height h2
    cin >> w1 >> w2 >> h1 >> h2;

    // Calculate base areas and maximum capacity for each layer
    long long area1 = (long long)w1 * w1;
    long long area2 = (long long)w2 * w2;
    long long vol1 = area1 * h1;
    long long vol2 = area2 * h2;
    long long max_capacity = vol1 + vol2; // Total cup capacity

    long long current_vol = 0;    // Total accumulated volume
    int current_height = 0;       // Current water level height
    int max_delta_h = 0;          // Record the maximum change in height

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        int prev_height = current_height; // Height before pouring
        
        // Update total volume; cap at max capacity if it overflows
        current_vol += v;
        if (current_vol > max_capacity) {
            current_vol = max_capacity;
        }

        // Calculate the new height after pouring
        int next_height;
        if (current_vol <= vol1) {
            // Still within the bottom layer
            next_height = (int)(current_vol / area1);
        } else {
            // Entered the top layer
            next_height = h1 + (int)((current_vol - vol1) / area2);
        }

        // Calculate height increase and update the maximum delta
        int delta_h = next_height - prev_height;
        if (delta_h > max_delta_h) {
            max_delta_h = delta_h;
        }

        current_height = next_height; // Update current height for next iteration
    }

    // Output the maximum height change observed
    cout << max_delta_h << endl;

    return 0;
}
