#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PointCloud.h"

#include "PCLViewer.h"

class PCLViewer;
class PointCloud : public QMainWindow
{
	Q_OBJECT

public:
	PointCloud(QWidget *parent = Q_NULLPTR);
	pcl::PointCloud<pcl::PointNormal>::Ptr getPointNormal();
	void ColorfulCloud();

private:	
	Ui::PointCloudClass ui;
	
	pcl::visualization::PCLVisualizer::Ptr _viewer;
	pcl::PointCloud<pcl::PointXYZ>::Ptr _cloud;
	pcl::PointCloud<pcl::RGB>::Ptr pPointsRGB;
	pcl::PointCloud<pcl::PointXYZRGBA>::Ptr pCloudShow;

	PCLViewer _pclViewer;

public:
	const float Resolution = 5.0f;
	std::map<Point, bool> flag; //标记点是否为排除点与固定点

private slots:
	void OnReadFile();										//	读pcd文件槽函数
	void open_pcd_file();
	void OnClear();
	void SaveAsPlY();										//		保存为ply格式
	void OnActionSearchKNear();
	void DrawBoundingBox();									//	给模型画包围盒

	void Triangulation();									//	用八叉树实现三角剖分

	/**********KT树实现点云数据的空间划分*************/
		
	void	greedyTriangulation_reconstruct();				//	贪婪三角算法
	void	poisson_reconstruct();							//	泊松重建

	/*********八叉树实现点云数据的空间划分*********/
	void SearchKNear(float x, float y, float z, int &k);									//	搜索八叉树中指定点的且半径为k领域点
	void ShowLeafNode();										//	显示空间划分的叶子节点
};
