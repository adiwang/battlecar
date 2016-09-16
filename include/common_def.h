#ifndef _COMMON_DEFINE_H
#define _COMMON_DEFINE_H
#include <string>

enum LeafPosture {
	LEAF_POS_OK = 0,
	LEAF_POS_ERR = 1,
};

struct LeafFeature {
	std::string id;		// id	产地-MachineID-YYmmddHHMMDD
	int Group;			// 分组
	int Rank;			// 分级

	//平均饱和度、平均色调、平均亮度；饱和度标准差、色度标准差、亮度标准差
	double AvgSaturation;
	double AvgHue;
	double AvgIntensity;
	double DeviationSaturation;
	double DeviationHue;
	double DeviationIntensity;
	
	//叶片长度、叶片宽度、叶片宽长比
	double Length;
	double Width;
	double WidthLengthRatio;

	double ApexAngle;	//叶尖角
	double Circularity; //圆度
	double Area;		//面积
	double ThickMean;	//平均厚度
	double DefectRate;	//残伤率
};

#endif  // _COMMON_DEFINE_H
