#include <pcl/io/pcd_io.h>
 
using namespace std;

int main(int argc, char** argv)
{
  // Object for storing the point cloud.
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
 
  // Read a PCD file from disk.
  if (pcl::io::loadPCDFile<pcl::PointXYZ>("../data/csite1.pcd", *cloud) != 0)
  {
    return -1;
  }

  for (size_t i = 0; i < cloud->points.size (); ++i)
    std::cerr << "    " << cloud->points[i].x << " " << cloud->points[i].y << " " << cloud->points[i].z << std::endl;

}
