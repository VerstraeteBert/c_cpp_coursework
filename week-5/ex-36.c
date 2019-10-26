#include <math.h>
#include <stdio.h>

typedef struct point{
    double x;
    double y;
} point;

double euclid_dist(const point * one, const point * two) {
    return sqrt(pow(one->x - two->x, 2) + pow(one->y - two->y, 2));
}

double manhattan_dist(const point * one, const point * two) {
    return fabs(one->x - two->x) + fabs(one->y - one->y);
}

double chebyshev_dist(const point * one, const struct point * two) {
    double x_diff = fabs(one->x - two->x);
    double y_diff = fabs(one->y - two->y);
    return x_diff > y_diff ? x_diff : y_diff;
}

double calc_max_dist(const point * points, size_t size, double(* diff)(const point *, const point *)) {
    double curr_max = -1;
    size_t i; size_t j; double curr_diff;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            curr_diff = diff(&points[i], &points[j]);
            curr_max = curr_max < curr_diff ? curr_diff : curr_max;
        }
    }
    return curr_max;
}

int main () {
   printf("How many points?\n");
   int num_points;
   scanf("%d", &num_points);
   point points [num_points];
   printf("Sure thing! Type %d points to compare: x , y\n", num_points);
   int i; double x, y;
   for (i = 0; i < num_points; i++) {
       scanf("%lf , %lf", &x, &y);
       point point = { x, y };
       points[i] = point;
   }

    printf("Max Euclid Dist: %lf\n", calc_max_dist(points, num_points, euclid_dist));
    printf("Max Manhattan Dist: %lf\n", calc_max_dist(points, num_points, manhattan_dist));
    printf("Max Chebyshev Dist: %lf\n", calc_max_dist(points, num_points, chebyshev_dist));

//   point one = {1,  5};
//   point two = {7,  2};
//   printf("Euclid: %lf\n", euclid_dist(&one, &two));
//   printf("Manhattan: %lf\n", manhattan_dist(&one, &two));
//   printf("Chebyshev: %fl\n", chebyshev_dist(&one, &two));
//
//   const point points [3] = {
//           {1, 5},
//           {2, 3},
//           {1000, 20}
//   };
//   double max_diff = calc_max_dist(points, sizeof(points) / sizeof(point), euclid_dist);
//   printf("Max diff is: %lf", max_diff);
}
