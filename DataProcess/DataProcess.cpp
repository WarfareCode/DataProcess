// DataProcess.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"Scenario.hpp"

#include <iostream>

using namespace sce;

int main()
{
    std::cout << "Scenario Class Test!"<<std::endl;

	//Vertex ver1(30,25);
	std::vector<Vertex> vertexs{ Vertex(30,25),Vertex(35,25),Vertex(35,30),Vertex(30,35) };

	std::vector<Platform> platforms{Platform("Platform1",PlatformType::LAND),
		Platform("Platform2",PlatformType::AIR),
		Platform("Platform3",PlatformType::SURFACE) };

	//Rf_values rfValues();
	std::vector<Rf_values> rfValues{ Rf_values (1,64,9000,9000,10),Rf_values(2,64,10000,10000,20) };
	Rf rf(9000,10000,rfValues, RfType::BURST);

	Pw_values pwValues(0,0,20,20,0);
	Pw pw(20,20, pwValues,PwType::FIX);

	std::vector<Pri_values> priValues{ Pri_values(1,0,90,90,0),Pri_values(2,0,93,93,0), Pri_values(3,0,97,97,0) };
	Pri pri(90,100,priValues,PriType::STAGGER);

	Radar_Mode radarMode1("001",ModeType::PULSE,rf,pw,pri,Scan(2,2,ScanType::SECTORIAL),Erp(50000,50000));
	Radar_Mode radarMode2("002", ModeType::PULSE, rf, pw, pri, Scan(2, 2, ScanType::SECTORIAL), Erp(100000, 100000));

	std::vector<std::shared_ptr<Radar_Mode>> ptrRadarModes{ std::make_shared<Radar_Mode>(radarMode1) };

	ptrRadarModes.push_back(std::make_shared<Radar_Mode>(radarMode2));

	Emitter emitter1("Emitter1",std::make_shared<Radar_Mode>(radarMode1));
	Emitter emitter2("Emitter2", ptrRadarModes);

	//emitter1.getPtr2RadarMode(0)->getPri().getPriValue(0).setMax(1000);

	std::cout << emitter1.getPtr2RadarMode(0)->getPri().getPriValue(0).getMax() ;
	std::cout << std::endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
