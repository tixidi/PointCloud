#pragma once

//	��Ƭ
class CFace
{
public:
	CFace(const pcl::PointXYZ &point1, const pcl::PointXYZ &point2, const pcl::PointXYZ &point3);
	CFace(const Point &point1, const Point &point2, const Point &point3);
	~CFace();

	Point GetPoint1()const;
	Point GetPoint2()const;
	Point GetPoint3()const;

	void  CFace::operator =(const CFace &p);
private:
	Point _point1;
	Point _point2;
	Point _point3;
};

// �������� std::list<CFace> ST