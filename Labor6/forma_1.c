typedef struct {
    int pole_position;
    double best_lap;
} qualifying_result;

typedef struct {
    int racing_number;
    char name[3];
    qualifying_result qualifying_results[3];

} pilot;

int main() {
    qualifying_result result1 = {1, 67.423};
    qualifying_result result2 = {3, 46.735};
    qualifying_result result3 = {1, 70.264};

    qualifying_result result4 = {2, 67.433};
    qualifying_result result5 = {5, 46.855};
    qualifying_result result6 = {3, 70.313};
    
    qualifying_result results2[] = {result4, result5, result6};
    qualifying_result results1[] = {result1, result2, result3};

    pilot pilot2 = {2, {'M', 'A', 'S'}, results2};
    pilot pilot1 = {1, {'M', 'S', 'C'}, results1};
    
    pilot t[2];
    t[0] = pilot1;
    t[1] = pilot2;

    return 0;
}