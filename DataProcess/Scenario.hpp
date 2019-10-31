/****************************************************************
*	Copyright(c)2019-2020 四川大学电子信息学院智能控制研究所
*	All right reserved.
*	
*	文件名称：Scenario.hpp
*	功能：提供XML解析数据封装类声明
*	当前版本：1.0
*	作者：韩露
*	完成日期：
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
		~Scenario(void);

	private:
		std::vector<Vertex> m_vertex;
		//由于Platform中name数据成员为string这种可变长类型，不应直接在容器中放置类对象，而应该使用指针
		std::vector<std::shared_ptr<Platform>> m_ptrPlatform;
	};

	Scenario::Scenario(void)
	{
	}

	Scenario::~Scenario(void)
	{
	}

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

	enum PlatformType
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

	enum RfType
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
		std::vector<Rf_values>& getRfValues(void);

		//判断Pri_values值不为空
		bool isValuesEmpty();

		//根据values的索引值获取不同values的对象。
		//在获取values前应判断容器是否为空
		Rf_values& getRfValues(unsigned int valueOrder);

		//add Rf_values
		void addRfValues(Rf_values &);

		//insert Rf_values
		bool insertRfValues(unsigned int pos, Rf_values &);

		//delete Rf_values
		bool deleteRfValues(unsigned int pos);

		//set method
		void setRfMin(const unsigned long &);
		void setRfMax(const unsigned long &);
		void setRfType(const RfType &);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setRfValues(const std::vector<Rf_values>&);
		
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

	enum PwType
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
		std::vector<Pw_values>& getPwValues(void);

		//判断Pri_values值不为空
		bool isValuesEmpty();

		//根据values的索引值获取不同values的对象。
		//在获取values前应判断容器是否为空
		Pw_values& getPwValue(unsigned int valueOrder);

		//add Pw_values
		void addPriValues(Pw_values &);

		//insert Pw_values
		bool insertPwValues(unsigned int pos, Pw_values &);
		
		//delete Pw_values
		bool deletePwValues(unsigned int pos);
		
		//set method
		void setPwMin(const unsigned long &);
		void setPwMax(const unsigned long &);
		void setPwType(const PwType &);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setPwValues(const std::vector<Pw_values>&);

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

	enum PriType
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
		std::vector<Pri_values>& getPriValues(void);

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

		//insert Pri_values
		bool insertPriValues(unsigned int pos, Pri_values &);
		
		//delete Pri_values
		bool deletePriValues(unsigned int pos);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setPriValues(const std::vector<Pri_values>&);
		
	private:
		unsigned long m_min=90;
		unsigned long m_max=100;
		PriType m_type = PriType::FIX;
		std::vector<Pri_values> m_values{ Pri_values() };

	public: 
		//const Pri_values &operator[](unsigned int valuesOrder) const;
	};

	enum ScanType
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

	enum ModeType
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
		void setRf(const Rf &);
		void setPw(const Pw &);
		void setPri(const Pri &);
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
		const std::shared_ptr<Radar_Mode> getRadarMode(unsigned int valueOrder) const ;

		//add method
		void addRadarMode(const std::shared_ptr<Radar_Mode>);
		
		//insert
		bool insertRadarMode(unsigned int pos, std::shared_ptr<Radar_Mode>);

		//delete
		bool deleteRadarMode(unsigned int pos);

		//set method
		void setName(const std::string& name);

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
	
	enum MissionType
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

		bool isTargetPointEmpty(void);

		//返回非常量引用可以连续调用成员变量类的成员函数
		Point& getTargetPoint(unsigned int pointOrder);

		void addTargetPoint(const Point&);

		bool insertTargetPoint(unsigned int pos, const Point&);

		bool deleteTargetPoint(unsigned int pos);

		void setMissionType(const MissionType&);
		void setStartPoint(const Point&);
		void setEndPoint(const Point&);


	private:
		MissionType m_type = MissionType::STRIKE;
		Point m_startPoint{Point()};
		Point m_endPoint{Point()};
		std::vector<Point> m_targetPoints{Point()};
	};
		
	class OwnPlatform
	{
	public:
		OwnPlatform();
		~OwnPlatform();

	private:

	};

	

}

#endif // !__SCENARIO__