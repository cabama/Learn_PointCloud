// transform.cpp
// Test para probrar las transformadas de Point Cloud.
// Carlos Barreiro Mata <barreymata@gmail.com>

// INCLUDES
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/common/transforms.h>
// NAMESPACES
using namespace std;
using namespace pcl;


// Funcion para leer una nuve de puntos de un fichero ASCII PCD
PointCloud<PointXYZ> readPCD (string path)
{
	// Object for storing the point cloud.
	PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);
	// Cargamos  
	if (pcl::io::loadPCDFile<PointXYZ>("../data/random.pcd", *cloud) != 0)
	{
		cout << "No se a cargado correctamente." << endl;
	}
	// Devolvemos la nube de puntos cargada
	return *cloud;
}



// Funcion para visualizar un cloud de puntos.
void viewview (PointCloud<PointXYZ> cloud, string titulo)
{
 
 	PointCloud<PointXYZ> *cloudPointer = &cloud;
	// Vamos a visualizar el contenido de los puntos. 
	pcl::visualization::CloudViewer viewer(titulo);
	viewer.showCloud(cloud.makeShared());
	while (!viewer.wasStopped())
	{
		// Do nothing but wait.
	}

}


// Por medio de esta funcion aplicamos la transformacion de prueba deseada.
void transformamos (PointCloud<PointXYZ> &cloud)
{
	PointCloud<PointXYZ>::Ptr cloudT(new PointCloud<PointXYZ>);
	Eigen::Matrix4f transformation = Eigen::Matrix4f::Identity();
 
	// Set a rotation around the Z axis (right hand rule).
	float theta = 90.0f * (M_PI / 180.0f); // 90 degrees.
	transformation(0, 0) = cos(theta);
	transformation(0, 1) = -sin(theta);
	transformation(1, 0) = sin(theta);
	transformation(1, 1) = cos(theta);

	pcl::transformPointCloud(cloud, cloud, transformation);
}


// Funcion Main donde se desarrolla todo el codigo.
int main (int argc, char** argv)
{

	cout << "Inicio del programa" << endl;
	cout << "Vamos a cargar el fichero PCD tipo ASCII" << endl;
	PointCloud<PointXYZ> cloud = readPCD("../data/random.pcd");
	cout << "Se va a transformar la matriz de puntos" << endl;
	viewview(cloud, "Normal");
	transformamos(cloud);
	viewview(cloud, "Transformada");
	cout << "Final del Programa" << endl;

}	