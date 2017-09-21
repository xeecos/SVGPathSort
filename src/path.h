#ifndef _PATH_H_
#define _PATH_H_
#include <vector>
using namespace std;
enum PointType
{
	MOVE_TO,
	LINT_TO
};
struct Point
{
	PointType type;
	float x, y;
};
typedef vector<Point> Path;
typedef vector<Path> Paths;

void optimize_path(const Paths &data, vector<int> &path_order, vector<int> &path_start)
{
	path_order.push_back(2);
	path_start.push_back(3);
	path_order.push_back(1);
	path_start.push_back(4);
}
#endif // #ifndef _PATH_H_