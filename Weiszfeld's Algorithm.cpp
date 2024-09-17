// Function to calculate Euclidean distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
// Weiszfeld's algorithm to compute the geometric median
pair<double, double> weiszfeld_algorithm(const vector<pair<double, double>>& points,int max_iter=1000,double EPSILON = 1e-7 ) {
    double x_center = 0, y_center = 0;

    // Initial guess: arithmetic mean of all points
    for (const auto& p : points) {
        x_center += p.first;
        y_center += p.second;
    }
    x_center /= points.size();
    y_center /= points.size();
    for(int it=0;it<max_iter;it++) {
        double num_x = 0, num_y = 0, denom = 0;
        bool allSamePoint = true;
        // Update x_center and y_center using Weiszfeld's formula
        for (const auto& p : points) {
            double x_i = p.first;
            double y_i = p.second;
            double dist = distance(x_center, y_center, x_i, y_i);
            if (dist > EPSILON) {  // Avoid division by zero
                num_x += x_i / dist;
                num_y += y_i / dist;
                denom += 1 / dist;
                allSamePoint = false;
            }
            else{
                num_x+=x_i;
                num_y+=y_i;
                denom+=1.0;
            }
        }
        if(allSamePoint)return {x_center, y_center};
        if (abs(denom) < EPSILON) {
            // If denominator is too close to zero, return the current center
            return {x_center, y_center};
        }
        double new_x_center = num_x / denom;
        double new_y_center = num_y / denom;
        // Check for convergence
        if (distance(x_center, y_center, new_x_center, new_y_center) < EPSILON) {
            break;
        }
        // Update the center for the next iteration
        x_center = new_x_center;
        y_center = new_y_center;
    }
    return {x_center, y_center};
}