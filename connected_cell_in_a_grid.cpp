#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int get_region_size(vector< vector<int> > &grid, int i, int j) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;
  int size = 1;
  grid[i][j] = 0;
  for (int r = i - 1; r <= i + 1; r++) {
    for (int c = j - 1; c <= j + 1; c++) {
      if (r != i || c != j) {
        size += get_region_size(grid, r, c);
      }
    }
  }
  return size;
}

int get_biggest_region(vector< vector<int> > grid) {
  int max_size = 0;
  int curr_size = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] == 1) {
        curr_size = get_region_size(grid, i, j);
        max_size = max(max_size, curr_size);
      }
    }
  }
  return max_size;
}