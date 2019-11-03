/****************************************************************
*	Copyright(c)2019-2020 四川大学电子信息学院智能控制研究所
*	All right reserved.
*	
*	文件名称：Scenario.hpp
*	功能：提供XML解析数据封装类声明
*	当前版本：1.0
*	作者：韩露
*	完成日期：2019-11-3
******************************************************************/

#ifndef __SCENARIO__
#define __SCENARIO__

#include<stdexcept>
#include<string>
#include<vector>
#include <memory>

namespace sce 
{
	class Vertex;
	class Platform;
	class Rf_values;
	class Rf;
	class Pw_values;
	class Pw;
	class Pri_values;
	class Pri;
	class Scan;
	class Erp;
	class Radar_Mode;
	class Emitter;
	class Weapon;
	class Site;
	class Point;
	class Mission;
	class OwnPlatform;
	class Esm;
	class Ecm;
	class WayPoint;
	class Route;
	class Location;
	class DwellSquence;
	class EsmStrategySection;
	class EsmStrategy;
	class EcmStrategySection;
	class EcmStrategy;
	class PlatformSiteRelation;
	class PlatformEmitterRelation;
	class PlatformWeaponRelation;
	class OwnPlatformEsmRelation;
	class EsmEsmStrategyRelation;
	class OwnPlatformEcmRelation;
	class EcmEcmStrategyRelation;
	class OwnPlatformRouteRelation;

	class Error : public std::runtime_error
	{
	public:
		Error (const std::string &msg)
			:std::runtime_error(std::string("Scenario:").append(msg)) 
		{}
		//~Error (void);

	private:

	};

	class Scenario
	{
	public:
		Scenario(void); 
		Scenario(std::vector<Vertex>& vertexs,
			std::vector<std::shared_ptr<Platform>> ptrPlatforms,
			std::vector<std::shared_ptr<Emitter>> ptrEmitters,
			std::vector<std::shared_ptr<Weapon>> ptrWeapons,
			std::vector<std::shared_ptr<Site>> ptrSites,
			std::vector<std::shared_ptr<OwnPlatform>> ptrOwnPlatforms,
			std::vector<std::shared_ptr<Esm>> ptrEsms,
			std::vector<std::shared_ptr<Ecm>> ptrEcms,
			std::vector<std::shared_ptr<Route>> ptrRoutes,
			std::vector<std::shared_ptr<EsmStrategy>> ptrEsmStrategy,
			std::vector<std::shared_ptr<EcmStrategy>> ptrEcmStrategy,
			std::vector<PlatformSiteRelation> ptrPlatformSiteRelations,
			std::vector<PlatformEmitterRelation> ptrPlatformEmitterRelations,
			std::vector<PlatformWeaponRelation> ptrPlatformWeaponRelations,
			std::vector<OwnPlatformEsmRelation> ptrOwnPlatformEsmRelations,
			std::vector<EsmEsmStrategyRelation> ptrEsmEsmStrategyRelations,
			std::vector<OwnPlatformEcmRelation> ptrOwnPlatformEcmRelations,
			std::vector<EcmEcmStrategyRelation> ptrEcmEcmStrategyRelations,
			std::vector<OwnPlatformRouteRelation> ptrOwnPlatformRouteRelations);

		~Scenario(void);

	private:
		std::vector<Vertex> m_vertex{Vertex()};
		//由于Platform中name数据成员为string这种可变长类型，不应直接在容器中放置类对象，而应该使用指针
		std::vector<std::shared_ptr<Platform>> m_ptrPlatform{std::make_shared<Platform>()};

		std::vector<std::shared_ptr<Emitter>> m_ptrEmitter{ std::make_shared<Emitter>() };
		std::vector<std::shared_ptr<Weapon>> m_ptrWeapon{ std::make_shared<Weapon>() };

		std::vector<std::shared_ptr<Site>> m_ptrSite{ std::make_shared<Site>() };
		std::vector<std::shared_ptr<OwnPlatform>> m_ptrOwnPlatform{ std::make_shared<OwnPlatform>() };

		std::vector<std::shared_ptr<Esm>> m_ptrEsm{ std::make_shared<Esm>() };
		std::vector<std::shared_ptr<Ecm>> m_ptrEcm{ std::make_shared<Ecm>() };

		std::vector<std::shared_ptr<Route>> m_ptrRoute{ std::make_shared<Route>() };

		std::vector<std::shared_ptr<EsmStrategy>> m_ptrEsmStrategy{ std::make_shared<EsmStrategy>() };
		std::vector<std::shared_ptr<EcmStrategy>> m_ptrEcmStrategy{ std::make_shared<EcmStrategy>() };

		std::vector<PlatformSiteRelation> m_PlatformSiteRelation{PlatformSiteRelation()};
		std::vector<PlatformEmitterRelation> m_PlatformEmitterRelation{PlatformEmitterRelation()};
		std::vector<PlatformWeaponRelation> m_PlatformWeaponRelation{PlatformWeaponRelation()};
		std::vector<OwnPlatformEsmRelation> m_OwnPlatformEsmRelation{OwnPlatformEsmRelation()};
		std::vector<EsmEsmStrategyRelation> m_EsmEsmStrategyRelation{EsmEsmStrategyRelation()};
		std::vector<OwnPlatformEcmRelation> m_OwnPlatformEcmRelation{OwnPlatformEcmRelation()};
		std::vector<EcmEcmStrategyRelation> m_EcmEcmStrategyRelation{EcmEcmStrategyRelation()};
		std::vector<OwnPlatformRouteRelation> m_OwnPlatformRouteRelation{OwnPlatformRouteRelation()};

	};

	class Vertex
	{
	public:
		
		Vertex(void)=default;

		Vertex(const double &, const double &);

		~Vertex(void);

		//get latitude and longitude
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;

		//set latitude and longitute
		void setLatitude(const double &);
		void setLongitude(const double &);

	private:
		double m_latitude=0.0, m_longitude=0.0;
	};

	enum class PlatformType
	{
		LAND = 0,
		AIR = 1,
		SURFACE = 2
	};

	
	class Platform
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Platform(void)=default;

		Platform(const std::string &, const PlatformType &);

		~Platform(void);

		//get PlatformName and PlatformType
		const std::string& getPlatformName(void) const;
		const PlatformType& getPlatformType(void) const;

		//set PlatformName and PlatformType
		void setPlatformName(const std::string &);
		void setPlatformType(const PlatformType &);
	private:
		std::string m_name{ "Platform1" };
		PlatformType m_type=PlatformType::LAND;
	};

	class Rf_values
	{
	public:
		Rf_values(void)=default;

		Rf_values(const unsigned int &,
			const unsigned int &,
			const unsigned long &,
			const unsigned long &,
			const unsigned long &);

		~Rf_values(void);

		//get method
		const unsigned int& getPhaseOrder(void) const;
		const unsigned int& getNumberOfPulses(void) const;
		const unsigned long& getMin(void) const;
		const unsigned long& getMax(void) const;
		const unsigned long& getSweepTime(void) const;

		//set method
		void setPhaseOrder(const unsigned int &);
		void setNumberOfPulses(const unsigned int &);
		void setMin(const unsigned long &);
		void setMax(const unsigned long &);
		void setSweepTime(const unsigned long &);

	private:
		unsigned int m_phaseOrder = 1;
		unsigned int m_numberOfPulses = 0;
		unsigned long m_min = 90;
		unsigned long m_max = 90;
		unsigned long m_sweepTime = 0;
	};

	enum class RfType
	{
		BURST = 0,
		FIX=1
	};

	class Rf
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Rf(void) = default;
		Rf(const unsigned long &,
			const unsigned long &,
			const RfType &);

		Rf(const unsigned long &,
			const unsigned long &,
			const Rf_values &, 
			const RfType &);
		Rf(const unsigned long &,
			const unsigned long &,
			const std::vector<Rf_values> &, 
			const RfType &);

		//Rf(const Rf& rf);
		//Rf& operator=(const Rf& rf);
		~Rf(void);

		//get mehtod
		const unsigned long& getRfMin(void) const;
		const unsigned long& getRfMax(void) const;
		const RfType& getRfType(void) const;

		//获取容纳Pri_values的容器对象
		std::vector<Rf_values>& getAllRfValues(void);

		//判断Pri_values值不为空
		bool isValuesEmpty();

		//根据values的索引值获取不同values的对象。
		//在获取values前应判断容器是否为空
		Rf_values& getRfValue(const unsigned int& valueOrder);

		//add Rf_values
		void addRfValues(const Rf_values &);

		//Values值设置/替换
		bool setRfValues(const unsigned int& pos, const Rf_values &);

		//insert Rf_values
		bool insertRfValues(const unsigned int& pos, const Rf_values &);

		//delete Rf_values
		bool deleteRfValues(const unsigned int& pos);

		//set method
		void setRfMin(const unsigned long &);
		void setRfMax(const unsigned long &);
		void setRfType(const RfType &);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setAllRfValues(const std::vector<Rf_values>&);
		
	private:
		unsigned long m_min=9000;
		unsigned long m_max=10000;
		RfType m_type=RfType::BURST;
		std::vector<Rf_values> m_values{ Rf_values() };

	public:
		//const Rf_values &operator[](unsigned int valuesOrder) const;
	};

	class Pw_values
	{
	public:
		
		Pw_values(void)=default;

		Pw_values(const unsigned int &,
			const unsigned int &,
			const unsigned long &,
			const unsigned long &,
			const unsigned long &)
		{}
		~Pw_values(void);

		//get method
		const unsigned int& getPhaseOrder(void) const;
		const unsigned int& getNumberOfPulses(void) const;
		const unsigned long& getMin(void) const;
		const unsigned long& getMax(void) const;
		const unsigned long& getSweepTime(void) const;

		//set method
		void setPhaseOrder(const unsigned int &);
		void setNumberOfPulses(const unsigned int &);
		void setMin(const unsigned long &);
		void setMax(const unsigned long &);
		void setSweepTime(const unsigned long &);

	private:
		unsigned int m_phaseOrder=0;
		unsigned int m_numberOfPulses=0;
		unsigned long m_min=20;
		unsigned long m_max=20;
		unsigned long m_sweepTime=0;
	};

	enum class PwType
	{
		FIX = 0
	};

	class Pw
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Pw(void)=default;
		Pw(const unsigned long &, 
			const unsigned long &, 
			const PwType &);

		Pw(const unsigned long &,
			const unsigned long &,
			const Pw_values &,
			const PwType &);
		Pw(const unsigned long &,
			const unsigned long &,
			const std::vector<Pw_values > &,
			const PwType &);
		~Pw(void);

		//get mehtod
		const unsigned long& getPwMin(void) const;
		const unsigned long& getPwMax(void) const;
		const PwType& getPwType(void) const;

		//获取容纳Pri_values的容器对象
		std::vector<Pw_values>& getAllPwValues(void);

		//判断Pri_values值不为空
		bool isValuesEmpty();

		//根据values的索引值获取不同values的对象。
		//在获取values前应判断容器是否为空
		Pw_values& getPwValue(unsigned int valueOrder);

		//add Pw_values
		void addPriValues(Pw_values &);

		//Values值设置/替换
		bool setPwValues(const unsigned int& pos, const Pw_values &);

		//insert Pw_values
		bool insertPwValues(unsigned int pos, Pw_values &);
		
		//delete Pw_values
		bool deletePwValues(unsigned int pos);
		
		//set method
		void setPwMin(const unsigned long &);
		void setPwMax(const unsigned long &);
		void setPwType(const PwType &);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setAllPwValues(const std::vector<Pw_values>&);

	private:
		unsigned long m_min=20;
		unsigned long m_max=20;
		PwType m_type=PwType::FIX;
		std::vector<Pw_values> m_values{ Pw_values() };

	public:
		//const Pw_values &operator[](unsigned int valuesOrder) const;
	};

	class Pri_values
	{
	public:
		Pri_values(void) = default;
		
		Pri_values(const unsigned int &,
			const unsigned int &,
			const unsigned long &,
			const unsigned long &,
			const unsigned long &);

		~Pri_values(void);

		//get method
		const unsigned int& getPhaseOrder(void) const;
		const unsigned int& getNumberOfPulses(void) const;
		const unsigned long& getMin(void) const;
		const unsigned long& getMax(void) const;
		const unsigned long& getSweepTime(void) const;

		//set method
		void setPhaseOrder(const unsigned int &);
		void setNumberOfPulses(const unsigned int &);
		void setMin(const unsigned long &);
		void setMax(const unsigned long &);
		void setSweepTime(const unsigned long &);

	private:
		unsigned int m_phaseOrder=1;
		unsigned int m_numberOfPulses=0;
		unsigned long m_min=90;
		unsigned long m_max=90;
		unsigned long m_sweepTime=0;
	};

	enum class PriType
	{
		STAGGER = 0,
		SWITCHING=1,
		FIX=2
	};

	class Pri
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Pri(void) = default;
		Pri(const unsigned long &,
			const unsigned long &,
			const PriType &);

		Pri(const unsigned long &,
			const unsigned long &,
			const Pri_values &,
			const PriType &);

		Pri(const unsigned long &,
			const unsigned long &,
			const std::vector<Pri_values> &,
			const PriType &);

		~Pri(void);


		//get mehtod
		const unsigned long& getPriMin(void) const;
		const unsigned long& getPriMax(void) const;
		const PriType& getPriType(void) const;

		//获取容纳Pri_values的容器对象
		std::vector<Pri_values>& getAllPriValues(void);

		//判断Pri_values值不为空
		bool isValuesEmpty();

		//根据Pri_value的顺序获取不同Pri_values的对象。
		//在获取Pri_value前应判断容器是否为空
		Pri_values& getPriValue(unsigned int valueOrder);
		
		//set method
		void setPriMin(const unsigned long &);
		void setPriMax(const unsigned long &);
		void setPriType(const PriType &);
		
		//add Pri_values
		void addPriValues(Pri_values &);

		//Values值设置/替换
		bool setPriValues(const unsigned int& pos, const Pri_values &);

		//insert Pri_values
		bool insertPriValues(unsigned int pos, Pri_values &);
		
		//delete Pri_values
		bool deletePriValues(unsigned int pos);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setAllPriValues(const std::vector<Pri_values>&);
		
	private:
		unsigned long m_min=90;
		unsigned long m_max=100;
		PriType m_type = PriType::FIX;
		std::vector<Pri_values> m_values{ Pri_values() };

	public: 
		//const Pri_values &operator[](unsigned int valuesOrder) const;
	};

	enum class ScanType
	{
		SECTORIAL=0
	};

	class Scan
	{
	public:
		
		Scan(void) = default;
		Scan(const unsigned int &,
			const unsigned int &,
			const ScanType &);
		~Scan(void);

		//get mehtod
		const unsigned int& getScanMin(void) const;
		const unsigned int& getScanMax(void) const;
		const ScanType& getScanType(void) const;
		
		//set method
		void setScanMin(const unsigned long &);
		void setScanMax(const unsigned long &);
		void setScanType(const ScanType &);
		
	private:
		unsigned int m_min=2;
		unsigned int m_max=2;
		ScanType m_type = ScanType::SECTORIAL;
	};

	class Erp
	{
	public:
		
		Erp(void) = default;
		Erp(const unsigned long &,
			const unsigned long &);
		~Erp(void);

		//get mehtod
		const unsigned long& getErpMin(void) const;
		const unsigned long& getErpMax(void) const;
		
		//set method
		void setErpMin(const unsigned long &);
		void setErpMax(const unsigned long &);
		

	private:
		unsigned long m_min=50000;
		unsigned long m_max=50000;
	};

	enum class ModeType
	{
		PULSE=0
	};

	class Radar_Mode
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Radar_Mode(void);

		Radar_Mode(const std::string &,
			const ModeType &,
			const Rf &,
			const Pw &,
			const Pri &,
			const Scan &,
			const Erp &);
		~Radar_Mode(void);

		//get mehtod
		const std::string& getModeCode(void) const;
		const ModeType& getModeType(void) const;
		Rf& getRf(void);
		Pw& getPw(void);
		Pri& getPri(void);
		Scan& getScan(void);
		Erp& getErp(void);

		//set method
		void setModeCode(const std::string &);
		void setModeType(const ModeType &);
		void setRf(Rf &);
		void setPw(Pw &);
		void setPri(Pri &);
		void setScan(const Scan &);
		void setErp(const Erp &);

	private:
		std::string m_modeCode{ "001" };//直接初始化
		ModeType m_modeType=ModeType::PULSE;
		Rf m_rf{Rf()};
		Pw m_pw{Pw()};
		Pri m_pri{Pri()};
		Scan m_scan{Scan()};
		Erp m_erp{Erp()};
	};

	class Emitter
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Emitter(void);
		Emitter(const std::string &, std::shared_ptr<Radar_Mode> &);
		Emitter(const std::string &, std::vector<std::shared_ptr<Radar_Mode>> &);
		~Emitter(void);

		//get method
		const std::string& getName(void) const ;

		//获取RadarMode容器对象
		std::vector<std::shared_ptr<Radar_Mode>>& getAllPtr2RadarModes(void);

		//按索引获取RadarMode
		const std::shared_ptr<Radar_Mode> getPtr2RadarMode(unsigned int valueOrder) const ;

		//add method
		void addRadarMode(const std::shared_ptr<Radar_Mode>);
		
		//按照索引设置/修改RadarMode
		bool setPtr2RadarMode(unsigned int& pos, std::shared_ptr<Radar_Mode>);

		//insert
		bool insertRadarMode(unsigned int& pos, std::shared_ptr<Radar_Mode>);

		//delete
		bool deleteRadarMode(unsigned int& pos);

		//set method
		void setName(const std::string& name);

		//整体设置修改RadarMode
		void setAllPtr2RadarModes(std::vector<std::shared_ptr<Radar_Mode>>&);

	private:
		std::string m_name{"Emitter1"};
		std::vector<std::shared_ptr<Radar_Mode>> m_ptrRadarMode{ std::make_shared<Radar_Mode>() };
	};

	class Weapon
	{
	public:
		//不用使用标准容器类直接装带有string类型成员数据的类对象，而应该是该对象的指针
		Weapon(void);
		Weapon(const std::string&,const unsigned long&, const unsigned long&);
		~Weapon(void);

		const std::string& getName(void) const;
		const unsigned long& getCEPR(void) const;
		const unsigned long& getWeaponAreaCoverage(void) const;

		void setName(const std::string&);
		void setCEPR(const unsigned long&);
		void setWeaponAreaCoverage(const unsigned long&);


	private:
		std::string m_name{"Weapon 1"};
		unsigned long m_cepr{50000};
		unsigned long m_weaponAreaCoverage{100000};
	};

	class Site
	{
	public:
		//不用使用标准容器类直接装带有string类型成员数据的类对象，而应该是该对象的指针
		Site(void);
		Site(const std::string&, const double&, const double&, const double&);
		~Site(void);

		//get latitude and longitude
		const std::string& getName(void) const;
		const double& getAltitude(void) const;
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;

		//set latitude and longitute
		void setName(const std::string&);
		void setAltitude(const double &);
		void setLatitude(const double &);
		void setLongitude(const double &);

	private:
		std::string m_name{ "Site1" };
		double m_altitude{ 100.0 };
		double m_latitude{ 0.0 };
		double m_longitude{ 0.0 };
	};

	class Point
	{
	public:
		Point(void);
		Point(const double&, const double&, const double&, const double&, const double&);
		~Point(void);

		//get latitude and longitude
		const double& getAltitude(void) const;
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;
		const double& getTmin(void) const;
		const double& getTmax(void) const;

		//set latitude and longitute
		void setAltitude(const double &);
		void setLatitude(const double &);
		void setLongitude(const double &);
		void setTmin(const double &);
		void setTmax(const double &);

	private:
		double m_altitude{ 0.0 };
		double m_latitude{ 0.0 };
		double m_longitude{ 0.0 };
		double m_tmin{ 0.0 };
		double m_tmax{ 0.0 };
	};
	
	enum class MissionType
	{
		STRIKE = 0,
		SUPPORT=1
	};

	class Mission
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		Mission(void);

		//Mission Type:Strike
		Mission(const MissionType&, const Point&, const Point&, const std::vector<Point>&);
		Mission(const MissionType&, const Point&, const Point&, const Point&);

		//Mission Type:Support
		//此构造函数应该在MissionType为Support时才用此构造函数，但一如前面所说，不保证安全性
		Mission(const MissionType&,const Point&, const Point&);
		~Mission(void);

		const MissionType& getMissionType(void) const ;
		Point& getStartPoint(void);
		Point& getEndPoint(void);

		//获取容纳所有TargetPoints的容器对象
		std::vector<Point>& getAllTargetPoints(void);
		
		bool isTargetPointEmpty(void);

		//返回非常量引用可以连续调用成员变量类的成员函数
		Point& getTargetPoint(unsigned int& pointOrder);

		void addTargetPoint(const Point&);

		bool setTargetPoint(unsigned int& pos, const Point&);

		bool insertTargetPoint(unsigned int& pos, const Point&);

		bool deleteTargetPoint(unsigned int& pos);

		void setMissionType(const MissionType&);
		void setStartPoint(const Point&);
		void setEndPoint(const Point&);
		void setAllTargetPoints(const std::vector<Point>&);


	private:
		MissionType m_type = MissionType::STRIKE;
		Point m_startPoint{Point()};
		Point m_endPoint{Point()};
		std::vector<Point> m_targetPoints{Point()};
	};
		
	enum class OwnPlatformType
	{
		AIR=0
		
	};

	class OwnPlatform
	{
	public:
		OwnPlatform(void);
		OwnPlatform(const std::string&, const OwnPlatformType&,const double&, const double&, const double&, const double&, const double&, const double&, const Mission&);
		~OwnPlatform(void);

		const std::string& getName(void) const;
		const OwnPlatformType& getType(void) const;
		const double& getMaxAcceleration(void)const;
		const double& getMaxDeceleration(void)const;
		const double& getMaxClimbRate(void)const;
		const double& getMaxDiveRate(void)const;
		const double& getMaxSpeed(void)const;
		const double& getMaxTurnRadius(void)const;

		Mission& getMission(void);

		void setName(const std::string&);
		void setType(const OwnPlatformType&);
		void setMaxAcceleration(const double&);
		void setMaxDeceleration(const double&);
		void setMaxClimbRate(const double&);
		void setMaxDiveRate(const double&);
		void setMaxSpeed(const double&);
		void setMaxTurnRadius(const double&);

		void setMission(const Mission&);


	private:
		std::string m_name{"Platform 1"};
		OwnPlatformType m_type=OwnPlatformType::AIR;
		double m_maxAcceleration{9.8};
		double m_maxDeceleration{9.8};
		double m_maxClimbRate{30.0};
		double m_maxDiveRate{30.0};
		double m_maxSpeed{340.0};
		double m_maxTurnRadius{10000};
		Mission m_mission{Mission()};
	};

	class Esm
	{
	public:
		Esm(void);
		Esm(const std::string&, const double&, const unsigned int&, const unsigned long&, const unsigned long&, const unsigned int&, const unsigned int&);
		~Esm(void);

		const std::string& getName(void);
		const double& getDwellFreqResolution(void);
		const unsigned int& getTuningStep(void);
		const unsigned long& getRfCovMin(void);
		const unsigned long& getRfCovMax(void);
		const unsigned int& getNumPulsesAcquisition(void);
		const unsigned int& getNumPulsesAlarm(void);

		void setName(const std::string&);
		void setDwellFreqResolution(const double&);
		void setTuningStep(const int&);
		void setRfCovMin(const long&);
		void setRfCovMax(const long&);
		void setNumPulsesAcquisition(const int&);
		void setNumPulsesAlarm(const int&);
		
	private:
		std::string m_name{ "Esm1" };
		double m_dwellFreqResolution{100.0};
		unsigned int m_tuningStep{ 20 };
		unsigned long m_rfCovMin{ 500 };
		unsigned long m_rfCovMax{ 12000 };
		unsigned int m_numPulsesAcquisition{200};
		unsigned int m_numPulsesAlarm{100};
	};

	enum class Tech
	{
		NOISE = 0,
		VGPO = 1,
		FT = 2,
		RGPO = 3
	};

	class Ecm
	{
	public:
		Ecm(void);

		Ecm(const std::string&, const unsigned long&, const unsigned int&, const unsigned long&, const unsigned long&, const Tech&);

		Ecm(const std::string&, const unsigned long&, const unsigned int&, const unsigned long&, const unsigned long&, const std::vector<Tech>&);
		~Ecm(void);

		const std::string& getName(void);
		const unsigned long& getPt(void);
		const unsigned int& getGain(void);
		const unsigned long& getRfMin(void);
		const unsigned long& getRfMax(void);

		//获取装填所有Tech的容器对象
		std::vector<Tech>& getAllTechs(void);

		//判断装填所有Tech的容器中是否为空
		bool isTechEmpty(void);

		//根据索引值找寻对应的Tech
		const Tech& getTech(const unsigned int& order);

		//add Tech
		void addTech(const Tech&);

		//对单个Tech进行设置，更改
		bool setTech(const unsigned int& pos, const Tech&);

		//insert Tech
		bool insertTech(const unsigned int& pos, const Tech&);

		//delete Tech
		bool deleteTech(const unsigned int& pos);

		//set method
		void setName(const std::string&);
		void setPt(const unsigned long&);
		void setGain(const unsigned int&);
		void setRfMin(const unsigned long&);
		void setRfMax(const unsigned long&);

		//以容器为单位，整体赋值修改
		void setAllTechs(const std::vector<Tech>&);

	private:
		std::string m_name{ "Ecm1" };
		unsigned long m_pt{ 20000 };
		unsigned int m_gain{ 10 };
		unsigned long m_rfMin{ 9000 };
		unsigned long m_rfMax{ 9500 };
		std::vector<Tech> m_techName{Tech::NOISE};
	};

	class WayPoint
	{
	public:
		WayPoint(void);
		WayPoint(const unsigned int&, const double&, const double&, const double&, const double&, const double&, const double&);
		~WayPoint(void);

		//get latitude and longitude
		const unsigned int& getIndex(void) const;
		const double& getAltitude(void) const;
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;
		const double& getTime(void) const;
		const double& getVelocity(void) const;
		const double& getAcceleration(void) const;

		//set latitude and longitute
		void setIndex(const unsigned int &);
		void setAltitude(const double &);
		void setLatitude(const double &);
		void setLongitude(const double &);
		void setTime(const double &);
		void setVelocity(const double&);
		void setAcceleration(const double&);

	private:
		unsigned int m_index{1};
		double m_altitude{ 0.0 };
		double m_latitude{ 0.0 };
		double m_longitude{ 0.0 };
		double m_time{ 0.0 };
		double m_velocity{ 200.0 };
		double m_acceleration{0.0};
	};

	class Route
	{
	public:
		Route(void);
		Route(const std::string&, const WayPoint&);
		Route(const std::string&, const std::vector<WayPoint>&);
		~Route(void);

		//get name
		const std::string& getName(void);

		//get waypoint by index
		WayPoint& getWayPoint(const unsigned int&);

		//get all waypoints
		std::vector<WayPoint>& getAllWayPoints(void);

		//add waypoint
		void addWayPoint(const WayPoint&);

		//insert waypoint by position
		bool insertWayPoint(const unsigned int&, const WayPoint&);

		//set/moditify waypoint by index
		bool setWayPoint(const unsigned int&, const WayPoint&);

		//detele waypoint by index
		bool deleteWayPoint(const unsigned int&);

		//set name
		void setName(const std::string&);

		//set/moditify WayPoints
		void setAllWayPoints(const std::vector<WayPoint>&);

	private:
		std::string m_name{"Route1"};
		std::vector<WayPoint> m_wayPoints{WayPoint()};
	};

	class Location
	{
	public:
		Location(void);
		Location(const double&, const double&, const double&);
		~Location(void);

		//get latitude and longitude
		const double& getAltitude(void) const;
		const double& getLatitude(void) const;
		const double& getLongitude(void) const;

		//set latitude and longitute
		void setAltitude(const double &);
		void setLatitude(const double &);
		void setLongitude(const double &);

	private:
		double m_altitude{ 0.0 };
		double m_latitude{ 0.0 };
		double m_longitude{ 0.0 };
	};

	class DwellSquence
	{
	public:
		DwellSquence(void);
		DwellSquence(const unsigned int&, const unsigned long&, const unsigned long&, const double&, const double&);
		~DwellSquence(void);

		//get method;
		const unsigned int& getIndex(void);
		const unsigned long& getMinFreq(void);
		const unsigned long& getMaxFreq(void);
		const double& getStartTime(void);
		const double& getEndTime(void);

		//set method;
		void setIndex(const unsigned int&);
		void setMinFreq(const unsigned long&);
		void setMaxFreq(const unsigned long&);
		void setStartTime(const double&);
		void setEndTime(const double&);

	private:
		unsigned int m_index{ 1 };
		unsigned long m_minFreq{ 100 };
		unsigned long m_maxFreq{ 200 };
		double m_startTime{ 0.0 };
		double m_endTime{ 30.0 };
	};

	class EsmStrategySection
	{
	public:
		EsmStrategySection(void);
		EsmStrategySection(const double&, const double&, const Location&, const Location&, const DwellSquence&);
		EsmStrategySection(const double&, const double&, const Location&, const Location&, const std::vector<DwellSquence>&);
		~EsmStrategySection(void);

		//get method
		const double& getStartTime(void);
		const double& getEndTime(void);
		Location& getStartLocation(void);
		Location& getEndLocation(void);

		//get DwellSquence by index
		DwellSquence& getDwellSquence(const unsigned int& index);

		//get all DwellSquences
		std::vector<DwellSquence>& getAllDwellSquences(void);

		//add DwellSquence
		void addDwellSquence(const DwellSquence&);

		//insert DwellSquence
		bool insertDwellSquence(const unsigned int& pos, const DwellSquence&);

		//set/moditify DwellSquence
		bool setDwellSquence(const unsigned int& pos, const DwellSquence&);

		//delete DwellSquence
		bool deleteDwellSquence(const unsigned int& index);

		//set/moditify all DwellSquence
		void setDwellSquences(const std::vector<DwellSquence>&);

		void setStartTime(const double&);
		void setEndTime(const double&);
		void setStartLocation(const Location&);
		void setEndLocation(const Location&);

	private:
		double m_startTime{0};
		double m_endTime{100};
		Location m_startLocation{Location()};
		Location m_endLocation{Location()};
		std::vector<DwellSquence> m_dwellSquences{DwellSquence()};
	};

	class EsmStrategy
	{
	public:
		EsmStrategy(void);
		EsmStrategy(const std::string&, const std::shared_ptr<EsmStrategySection>&);
		EsmStrategy(const std::string&, const std::vector<std::shared_ptr<EsmStrategySection>>&);
		~EsmStrategy(void);

		//get method
		const std::string& getName(void) const;

		//获取EsmStrategySection指针容器对象
		std::vector<std::shared_ptr<EsmStrategySection>>& getAllPtr2Sections(void);

		//按索引获取EsmStrategySection
		const std::shared_ptr<EsmStrategySection> getPtr2Section(unsigned int& pos) const;

		//add EsmStrategySection
		void addSection(const std::shared_ptr<EsmStrategySection>);

		//按照索引设置/修改EsmStrategySection
		bool setPtr2Section(unsigned int& pos, std::shared_ptr<EsmStrategySection>);

		//insert EsmStrategySection
		bool insertSection(unsigned int& pos, std::shared_ptr<EsmStrategySection>);

		//delete EsmStrategySection
		bool deleteSection(unsigned int& pos);

		//set name
		void setName(const std::string& name);

		//整体设置修改EsmStrategySection指针容器对象
		void setAllPtr2Sections(std::vector<std::shared_ptr<EsmStrategySection>>&);

	private:
		std::string m_name{"ESM Strategy 1"};
		std::vector<std::shared_ptr<EsmStrategySection>> m_ptrSections{ std::make_shared<EsmStrategySection>() };

	};

	
	class EcmStrategySection
	{
	public:
		EcmStrategySection(void);
		EcmStrategySection(const double&, const double&, const Location&, const Location&,const Tech&);
		~EcmStrategySection(void);

		//get prop
		const double& getStartTime(void);
		const double& getEndTime(void);
		const Location& getStartLocation(void);
		const Location& getEndLocation(void); 
		const Tech& getTechName(void);

		//set prop
		void setStartTime(const double&);
		void setEndTime(const double&);
		void setStartLocation(const Location&);
		void setEndLocation(const Location&);
		void setTechName(const Tech&);

	private:
		double m_startTime{0.0};
		double m_endTime{100.0};
		Location m_startLocation{ Location() };
		Location m_endLocation{ Location() };
		Tech m_tech{ Tech::NOISE };
	};

	class EcmStrategy
	{
	public:
		EcmStrategy(void);
		EcmStrategy(const std::string&, const std::shared_ptr<EcmStrategySection>&);
		EcmStrategy(const std::string&, const std::vector<std::shared_ptr<EcmStrategySection>>&);
		~EcmStrategy(void);

		//get method
		const std::string& getName(void) const;

		//获取EcmStrategySection指针容器对象
		std::vector<std::shared_ptr<EcmStrategySection>>& getAllPtr2Sections(void);

		//按索引获取EsmStrategySection
		const std::shared_ptr<EcmStrategySection> getPtr2Section(unsigned int& pos) const;

		//add EsmStrategySection
		void addSection(const std::shared_ptr<EcmStrategySection>);

		//按照索引设置/修改EsmStrategySection
		bool setPtr2Section(unsigned int& pos, std::shared_ptr<EcmStrategySection>);

		//insert EsmStrategySection
		bool insertSection(unsigned int& pos, std::shared_ptr<EcmStrategySection>);

		//delete EsmStrategySection
		bool deleteSection(unsigned int& pos);

		//set name
		void setName(const std::string& name);

		//整体设置修改EsmStrategySection指针容器对象
		void setAllPtr2Sections(std::vector<std::shared_ptr<EcmStrategySection>>&);

	private:
		std::string m_name{ "ECM Strategy 1" };
		std::vector<std::shared_ptr<EcmStrategySection>> m_ptrSections{ std::make_shared<EcmStrategySection>() };
	};

	class PlatformSiteRelation
	{
	public:
		PlatformSiteRelation(void);
		PlatformSiteRelation(const std::shared_ptr<Platform>,const std::shared_ptr<Site>);
		~PlatformSiteRelation(void);

		//get name;
		const std::string& getPlatformName(void);
		const std::string& getSiteName(void);

		//set/moditify pointer of Object
		void setPlatform(const std::shared_ptr<Platform>);
		void setSite(const std::shared_ptr<Site>);
		

	private:
		std::shared_ptr<Platform> m_ptrPlatform{std::make_shared<Platform>()};
		std::shared_ptr<Site> m_ptrSite{ std::make_shared<Site>() };
	};

	class PlatformEmitterRelation
	{
	public:
		PlatformEmitterRelation(void);
		PlatformEmitterRelation(const std::shared_ptr<Platform>, const std::shared_ptr<Emitter>);
		~PlatformEmitterRelation(void);

		//get name;
		const std::string& getPlatformName(void);
		const std::string& getEmitterName(void);

		//set/moditify pointer of Object
		void setPlatform(const std::shared_ptr<Platform>);
		void setEmitter(const std::shared_ptr<Emitter>);

	private:
		std::shared_ptr<Platform> m_ptrPlatform{ std::make_shared<Platform>() };
		std::shared_ptr<Emitter> m_ptrEmitter{ std::make_shared<Emitter>() };
	};

	class PlatformWeaponRelation
	{
	public:
		PlatformWeaponRelation(void);
		PlatformWeaponRelation(const std::shared_ptr<Platform>, const std::shared_ptr<Weapon>);
		~PlatformWeaponRelation(void);

		//get name;
		const std::string& getPlatformName(void);
		const std::string& getWeaponName(void);

		//set/moditify pointer of Object
		void setPlatform(const std::shared_ptr<Platform>);
		void setWeapon(const std::shared_ptr<Weapon>);

	private:
		std::shared_ptr<Platform> m_ptrPlatform{ std::make_shared<Platform>() };
		std::shared_ptr<Weapon> m_ptrWeapon{ std::make_shared<Weapon>() };
	};

	class OwnPlatformEsmRelation
	{
	public:
		OwnPlatformEsmRelation(void);
		OwnPlatformEsmRelation(const std::shared_ptr<OwnPlatform>, const std::shared_ptr<Esm>);
		~OwnPlatformEsmRelation(void);

		//get name;
		const std::string& getOwnPlatformName(void);
		const std::string& getEsmName(void);

		//set/moditify pointer of Object
		void setOwnPlatform(const std::shared_ptr<OwnPlatform>);
		void setEsm(const std::shared_ptr<Esm>);

	private:
		std::shared_ptr<OwnPlatform> m_ptrOwnPlatform{ std::make_shared<OwnPlatform>() };
		std::shared_ptr<Esm> m_ptrEsm{ std::make_shared<Esm>() };
	};

	class EsmEsmStrategyRelation
	{
	public:
		EsmEsmStrategyRelation(void);
		EsmEsmStrategyRelation(const std::shared_ptr<Esm>, const std::shared_ptr<EsmStrategy>);
		~EsmEsmStrategyRelation(void);

		//get name;
		const std::string& getEsmName(void);
		const std::string& getEsmStrategyName(void);

		//set/moditify pointer of Object
		void setEsm(const std::shared_ptr<Esm>);
		void setEsmStrategy(const std::shared_ptr<EsmStrategy>);

	private:
		std::shared_ptr<Esm> m_ptrEsm{ std::make_shared<Esm>() };
		std::shared_ptr<EsmStrategy> m_ptrEsmStrategy{ std::make_shared<EsmStrategy>() };
	};

	class OwnPlatformEcmRelation
	{
	public:
		OwnPlatformEcmRelation(void);
		OwnPlatformEcmRelation(const std::shared_ptr<OwnPlatform>, const std::shared_ptr<Ecm>);
		~OwnPlatformEcmRelation(void);

		//get name;
		const std::string& getOwnPlatformName(void);
		const std::string& getEcmName(void);

		//set/moditify pointer of Object
		void setOwnPlatform(const std::shared_ptr<OwnPlatform>);
		void setEcm(const std::shared_ptr<Ecm>);

	private:
		std::shared_ptr<OwnPlatform> m_ptrOwnPlatform{ std::make_shared<OwnPlatform>() };
		std::shared_ptr<Ecm> m_ptrEcm{ std::make_shared<Ecm>() };
	};

	class EcmEcmStrategyRelation
	{
	public:
		EcmEcmStrategyRelation(void);
		EcmEcmStrategyRelation(const std::shared_ptr<Ecm>, const std::shared_ptr<EcmStrategy>);
		~EcmEcmStrategyRelation(void);

		//get name;
		const std::string& getEcmName(void);
		const std::string& getEcmStrategyName(void);

		//set/moditify pointer of Object
		void setEcm(const std::shared_ptr<Ecm>);
		void setEcmStrategy(const std::shared_ptr<EcmStrategy>);

	private:
		std::shared_ptr<Ecm> m_ptrEcm{ std::make_shared<Ecm>() };
		std::shared_ptr<EcmStrategy> m_ptrEcmStrategy{ std::make_shared<EcmStrategy>() };
	};

	class OwnPlatformRouteRelation
	{
	public:
		OwnPlatformRouteRelation(void);
		OwnPlatformRouteRelation(const std::shared_ptr<OwnPlatform>, const std::shared_ptr<Route>);
		~OwnPlatformRouteRelation(void);

		//get name;
		const std::string& getOwnPlatformName(void);
		const std::string& getRouteName(void);

		//set/moditify pointer of Object
		void setOwnPlatform(const std::shared_ptr<OwnPlatform>);
		void setRoute(const std::shared_ptr<Route>);

	private:
		std::shared_ptr<OwnPlatform> m_ptrOwnPlatform{ std::make_shared<OwnPlatform>() };
		std::shared_ptr<Route> m_ptrRoute{ std::make_shared<Route>() };
	};

}

#endif // !__SCENARIO__