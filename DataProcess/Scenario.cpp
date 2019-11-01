/****************************************************************
*	Copyright(c)2019-2020 四川大学电子信息学院智能控制研究所
*	All right reserved.
*
*	文件名称：Scenario.cpp
*	功能：提供XML解析数据封装类实现程序
*	当前版本：1.0
*	作者：韩露
*	完成日期：
******************************************************************/

#include "Scenario.hpp"
#include<iostream>
#include<cassert>

namespace sce 
{
	/***************************Vertex***********************************/
	Vertex::Vertex(void)
	{
	}
	
	Vertex::Vertex(const double &la, const double &lo)
		:m_latitude(la), m_longitude(lo)
	{

	}
	Vertex::~Vertex(void)
	{

	}

	
	inline const double& Vertex::getLatitude(void) const
	{
		return m_latitude;
	}

	inline const double& Vertex::getLongitude(void) const
	{
		return m_longitude;
	}

	void Vertex::setLatitude(const double & la)
	{
		m_latitude = la;
	}

	void Vertex::setLongitude(const double & lo)
	{
		m_longitude = lo;
	}
		
	/***************************Platform***********************************/
	Platform::Platform(void)
	{
	}

	Platform::Platform(const std::string &pname, const PlatformType &type)
		:m_name(pname), m_type(type)
	{

	}

	Platform::~Platform(void)
	{
	}

	const std::string& Platform::getPlatformName(void) const
	{
		return m_name;
	}
	const PlatformType & Platform::getPlatformType(void) const
	{
		return m_type; 
	}
	void Platform::setPlatformName(const std::string & name)
	{
		m_name = name; 
	}
	void Platform::setPlatformType(const PlatformType & type)
	{
		m_type = type;
	}

	/***************************Rf_values***********************************/
	Rf_values::Rf_values(void)
	{
	}

	Rf_values::Rf_values(const unsigned int &pOrder,
		const unsigned int &numOfPulses,
		const unsigned long &min,
		const unsigned long &max,
		const unsigned long &sweepTime)
		: m_phaseOrder(pOrder)
		, m_numberOfPulses(numOfPulses)
		, m_min(min)
		, m_max(max)
		, m_sweepTime(sweepTime)
	{
	}
	Rf_values::~Rf_values(void)
	{
	}

	const unsigned int & Rf_values::getPhaseOrder(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_phaseOrder; 
	}
	const unsigned int & Rf_values::getNumberOfPulses(void) const
	{
		return m_numberOfPulses;
	}
	const unsigned long & Rf_values::getMin(void) const
	{
		return m_min;
	}
	const unsigned long & Rf_values::getMax(void) const
	{
		return m_max;
	}
	const unsigned long & Rf_values::getSweepTime(void) const
	{
		return m_sweepTime;
	}

	void Rf_values::setPhaseOrder(const unsigned int & pOrder)
	{
		m_phaseOrder = pOrder;
	}
	void Rf_values::setNumberOfPulses(const unsigned int & numOfPulses)
	{
		m_numberOfPulses = numOfPulses;
	}
	void Rf_values::setMin(const unsigned long & min)
	{
		m_min = min;
	}
	void Rf_values::setMax(const unsigned long & max)
	{
		m_max = max;
	}
	void Rf_values::setSweepTime(const unsigned long & sweepTime)
	{
		m_sweepTime = sweepTime;
	}

	/************************Rf**********************************/
	//由于默认构造函数尚未进行Values值初始化，所以调用默认构造后应尽快添加Values值
	Rf::Rf(void)
	{
	}
	//由于默认构造函数尚未进行Values值初始化，所以调用默认构造后应尽快添加Values值
	Rf::Rf(const unsigned long &rfmin,
		const unsigned long &rfmax,
		const RfType &rftype)
		: m_min(rfmin)
		, m_max(rfmax)
		, m_type(rftype)
	{
	}

	Rf::Rf(const unsigned long &rfmin,
		const unsigned long &rfmax,
		const Rf_values & rfvalues,
		const RfType &rftype)
		:m_min(rfmin)
		, m_max(rfmax)
		, m_type(rftype)
		, m_values{ rfvalues }
	{
	}

	Rf::Rf(const unsigned long &rfmin,
		const unsigned long &rfmax,
		const std::vector<Rf_values>& rfvalues,
		const RfType &rftype)
		:m_min(rfmin)
		, m_max(rfmax)
		, m_type(rftype)
		, m_values(rfvalues)
	{
	}

	Rf::~Rf()
	{
		/*std::vector<Rf_values *>::iterator it;
		for (it = _rfValues.begin(); it != _rfValues.end(); it++)
		{
			delete *it;
			*it = nullptr;
		}*/
	}

	const unsigned long & Rf::getRfMin(void) const
	{
		return m_min;
	}

	const unsigned long & Rf::getRfMax(void) const
	{
		return m_max;
	}

	const RfType & Rf::getRfType(void) const
	{
		return m_type;
	}

	bool Rf::isValuesEmpty()
	{
		return m_values.empty() ? true : false;
	}

	Rf_values & Rf::getRfValues(unsigned int valueOrder)
	{
		assert(valueOrder >= m_values.size());
		if (valueOrder<m_values.size())
		{
			return m_values[valueOrder];
		}
		throw Error("can't return this value (doesn't exist)");
	}

	void Rf::addRfValues(Rf_values & rfvalues)
	{
		m_values.push_back(rfvalues);
	}

	bool Rf::insertRfValues(unsigned int pos, Rf_values & rfvalues)
	{
		assert(pos <= m_values.size());
		if (pos <= m_values.size())
		{
			m_values.insert(m_values.begin() + pos, rfvalues);
			return true;
		}
		return false;
	}

	bool Rf::deleteRfValues(unsigned int pos)
	{
		assert(pos >= m_values.size());
		if (pos<m_values.size())
		{
			//delete *(_rfValues.begin() + pos);
			m_values.erase(m_values.begin() + pos);
			return true;
		}
		return false;
	}

	void Rf::setRfMin(const unsigned long & rfmin)
	{
		m_min = rfmin;
	}

	void Rf::setRfMax(const unsigned long & rfmax)
	{
		m_max = rfmax;
	}

	void Rf::setRfType(const RfType & rftype)
	{
		m_type = rftype;
	}

	//inline const Rf_values& Rf::operator[](unsigned int valuesOrder) const
	//{
	//	// TODO: 在此处插入 return 语句
	//	return Rf::getRfValues(valuesOrder);
	//}

	/**************************Pw_Values*************************************/
	Pw_values::Pw_values(void)
	{
	}

	Pw_values::Pw_values(const unsigned int &pOrder,
		const unsigned int &numOfPulses,
		const unsigned long &min,
		const unsigned long &max,
		const unsigned long &sweepTime)
		: m_phaseOrder(pOrder)
		, m_numberOfPulses(numOfPulses)
		, m_min(min)
		, m_max(max)
		, m_sweepTime(sweepTime)
	{
	}

	Pw_values::~Pw_values(void)
	{
	}

	inline const unsigned int & Pw_values::getPhaseOrder(void) const
	{
		return m_phaseOrder;
	}
	const unsigned int & Pw_values::getNumberOfPulses(void) const
	{
		return m_numberOfPulses;
	}
	const unsigned long & Pw_values::getMin(void) const
	{
		return m_min;
	}
	const unsigned long & Pw_values::getMax(void) const
	{
		return m_max;
	}
	const unsigned long & Pw_values::getSweepTime(void) const
	{
		return m_sweepTime;
	}
	void Pw_values::setPhaseOrder(const unsigned int & pOrder)
	{
		m_phaseOrder = pOrder;
	}
	void Pw_values::setNumberOfPulses(const unsigned int & numOfPulses)
	{
		m_numberOfPulses = numOfPulses;
	}
	void Pw_values::setMin(const unsigned long & min)
	{
		m_min = min;
	}
	void Pw_values::setMax(const unsigned long & max)
	{
		m_max = max;
	}
	void Pw_values::setSweepTime(const unsigned long & sweepTime)
	{
		m_sweepTime = sweepTime;
	}
	
	/***************************PW************************************/
	//由于默认构造函数尚未进行Values值初始化，所以调用默认构造后应尽快添加Values值
	Pw::Pw(void)
	{
	}
	//由于默认构造函数尚未进行Values值初始化，所以调用默认构造后应尽快添加Values值
	Pw::Pw(const unsigned long &pwmin,
		const unsigned long &pwmax,
		const PwType &pwtype)
		:m_min(pwmin)
		, m_max(pwmax)
		, m_type(pwtype)
	{
	}

	Pw::Pw(const unsigned long &pwmin,
		const unsigned long &pwmax,
		const Pw_values &pwvalues, 
		const PwType &pwtype)
		:m_min(pwmin)
		,m_max(pwmax)
		,m_type(pwtype)
		,m_values{pwvalues}
	{
	}

	Pw::Pw(const unsigned long &pwmin,
		const unsigned long &pwmax,
		const std::vector<Pw_values>&pwvalues, 
		const PwType &pwtype)
		:m_min(pwmin)
		,m_max(pwmax)
		,m_type(pwtype)
		,m_values(pwvalues)
	{
		/*for (auto &it : pwvalues)
		{
			_pwValues.push_back(it);
		}*/
	}

	Pw::~Pw(void)
	{
		//_pwValues.clear();
		/*std::vector<std::shared_ptr<Pw_values>>::iterator it;
		for (it = _pwValues.begin(); it != _pwValues.end(); it++)
		{
			delete *it;
			*it = nullptr;
		}*/
	}

	const unsigned long & Pw::getPwMin(void) const
	{
		return m_min;
	}

	const unsigned long & Pw::getPwMax(void) const
	{
		return m_max;
	}

	const PwType & Pw::getPwType(void) const
	{
		return m_type;
	}

	bool Pw::isValuesEmpty()
	{
		return m_values.empty() ? true : false;
	}

	Pw_values & Pw::getPwValues(unsigned int valueOrder)
	{
		assert(valueOrder >= m_values.size());
		if (valueOrder<m_values.size())
		{
			//return *(_pwValues[valueOrder]);
			return m_values[valueOrder];
		}
		throw Error("can't return this value (doesn't exist)");
	}

	void Pw::addPriValues(Pw_values & pwvalues)
	{
		m_values.push_back(pwvalues);
	}

	bool Pw::insertPwValues(unsigned int pos, Pw_values & pwvalues)
	{
		assert(pos > m_values.size());
		if (pos <= m_values.size())
		{
			//_pwValues.insert(_pwValues.begin() + pos, &pwvalues);
			m_values.insert(m_values.begin() + pos, pwvalues);
			return true;
		}
		return false;
	}

	bool Pw::deletePwValues(unsigned int pos)
	{
		assert(pos >= m_values.size());
		if (pos<m_values.size())
		{
			//delete *(_pwValues.begin() + pos);
			m_values.erase(m_values.begin() + pos);
			return true;
		}
		return false;
	}

	void Pw::setPwMin(const unsigned long & pwmin)
	{
		m_min = pwmin;
	}

	void Pw::setPwMax(const unsigned long & pwmax)
	{
		m_max = pwmax;
	}

	void Pw::setPwType(const PwType & pwtype)
	{
		m_type = pwtype;
	}


	//inline const Pw_values & Pw::operator[](unsigned int valuesOrder) const
	//{
	//	// TODO: 在此处插入 return 语句
	//	return Pw::getPwValues(valuesOrder);
	//}

	/***************************Pri_Values************************************/
	Pri_values::Pri_values(void)
	{
	}

	Pri_values::Pri_values(const unsigned int &pOrder,
		const unsigned int &numOfPulses,
		const unsigned long &min,
		const unsigned long &max,
		const unsigned long &sweepTime)
		: m_phaseOrder(pOrder)
		, m_numberOfPulses(numOfPulses)
		, m_min(min)
		, m_max(max)
		, m_sweepTime(sweepTime)
	{
	}

	Pri_values::~Pri_values(void)
	{
	}
	const unsigned int & Pri_values::getPhaseOrder(void) const
	{
		return m_phaseOrder;
	}
	const unsigned int & Pri_values::getNumberOfPulses(void) const
	{
		return m_numberOfPulses;
	}
	const unsigned long & Pri_values::getMin(void) const
	{
		return m_min;
	}
	const unsigned long & Pri_values::getMax(void) const
	{
		return m_max;
	}
	const unsigned long & Pri_values::getSweepTime(void) const
	{
		return m_sweepTime;
	}
	void Pri_values::setPhaseOrder(const unsigned int & pOrder)
	{
		m_phaseOrder = pOrder;
	}
	void Pri_values::setNumberOfPulses(const unsigned int & numOfPulses)
	{
		m_numberOfPulses = numOfPulses;
	}
	void Pri_values::setMin(const unsigned long & min)
	{
		m_min = min;
	}
	void Pri_values::setMax(const unsigned long & max)
	{
		m_max = max;
	}
	void Pri_values::setSweepTime(const unsigned long & sweepTime)
	{
		m_sweepTime = sweepTime;
	}

	/***************************Pri************************************/
	//由于默认构造函数尚未进行Values值初始化，所以调用默认构造后应尽快添加Values值
	Pri::Pri(void)
	{
	}
	//由于构造函数尚未进行Values值初始化，所以调用默认构造后应尽快添加Values值
	Pri::Pri(const unsigned long &primin,
		const unsigned long &primax,
		const PriType &pritype)
		:m_min(primin)
		, m_max(primax)
		, m_type(pritype)
	{
	}

	Pri::Pri(const unsigned long &primin,
		const unsigned long &primax,
		const Pri_values &privalues,
		const PriType & pritype)
		:m_min(primin)
		, m_max(primax)
		, m_type(pritype)
		, m_values{ privalues }
	{
	}

	Pri::Pri(const unsigned long &primin, 
		const unsigned long &primax,
		const std::vector<Pri_values> &privalues,
		const PriType & pritype)
		:m_min(primin)
		,m_max(primax)
		,m_values( privalues )
		,m_type(pritype)
	{
	}

	Pri::~Pri(void)
	{
		/*std::vector<Pri_values *>::iterator it;
		for (it = _priValues.begin(); it != _priValues.end(); it++)
		{
			delete *it;
			*it = nullptr;
		}*/
	}
	inline const unsigned long & Pri::getPriMin(void) const
	{
		return m_min;
	}

	const unsigned long & Pri::getPriMax(void) const
	{
		return m_max;
	}

	const PriType & Pri::getPriType(void) const
	{
		return m_type;
	}

	std::vector<Pri_values>& Pri::getPriValues(void)
	{
		// TODO: 在此处插入 return 语句
		return m_values;
	}

	bool Pri::isValuesEmpty()
	{
		return m_values.empty() ? true : false;
	}

	Pri_values & Pri::getPriValue(unsigned int valueOrder)
	{
		assert(valueOrder>=m_values.size());
		if (valueOrder<m_values.size())
		{
			//return *(_priValues[valueOrder]);
			return m_values[valueOrder];
		}
		throw Error("can't return this value (doesn't exist)");
	}

	void Pri::setPriMin(const unsigned long & primin)
	{
		m_min = primin;
	}

	void Pri::setPriMax(const unsigned long & primax)
	{
		m_max = primax;
	}

	void Pri::setPriType(const PriType & pritype)
	{
		m_type = pritype;
	}

	void Pri::addPriValues(Pri_values & privalues)
	{
		m_values.push_back(privalues);
	}

	bool Pri::insertPriValues(unsigned int pos, Pri_values & privalues)
	{
		assert(pos > m_values.size());
		if (pos <= m_values.size())
		{
			m_values.insert(m_values.begin() + pos, privalues);
			return true;
		}
		return false;
	}

	bool Pri::deletePriValues(unsigned int pos)
	{
		assert(pos >= m_values.size());
		if (pos<m_values.size())
		{
			//delete *(_priValues.begin() + pos);
			m_values.erase(m_values.begin() + pos);
			return true;
		}
		return false;
	}

	void Pri::setPriValues(const std::vector<Pri_values>&priValues)
	{
		m_values=priValues;
	}

	//inline const Pri_values & Pri::operator[](unsigned int valuesOrder) const
	//{
	//	// TODO: 在此处插入 return 语句
	//	return Pri::getPriValues(valuesOrder);
	//}

	/**************************Scan*************************************/
	Scan::Scan(void)
	{
	}

	Scan::Scan(const unsigned int &max,
		const unsigned int &min,
		const ScanType &type)
		:m_min(min)
		, m_max(max)
		, m_type(type)
	{
	}

	Scan::~Scan(void)
	{
	}

	const unsigned int & Scan::getScanMin(void) const
	{
		return m_min;
	}

	const unsigned int & Scan::getScanMax(void) const
	{
		return m_max;
	}

	const ScanType & Scan::getScanType(void) const
	{
		return m_type;
	}

	void Scan::setScanMin(const unsigned long & min)
	{
		m_min = min;
	}

	void Scan::setScanType(const ScanType & type)
	{
		m_type = type;
	}

	void Scan::setScanMax(const unsigned long & max)
	{
		m_max = max;
	}

	/**************************Erp*************************************/
	Erp::Erp(void)
	{
	}

	Erp::Erp(const unsigned long &min,
		const unsigned long &max)
		:m_min(min),
		m_max(max)
	{
	}

	Erp::~Erp(void)
	{
	}
	const unsigned long & Erp::getErpMin(void) const
	{
		return m_min;
	}
	const unsigned long & Erp::getErpMax(void) const
	{
		return m_max;
	}
	void Erp::setErpMin(const unsigned long & min)
	{
		m_min = min;
	}
	void Erp::setErpMax(const unsigned long & max)
	{
		m_max = max;
	}
	
	/**************************Radar_Mode**********************************/
	//由于默认构造函数尚未进行Values值初始化，所以调用默认构造后应尽快添加Values值
	Radar_Mode::Radar_Mode(void)
	{
	}

	Radar_Mode::Radar_Mode(const std::string &modeCode,
		const ModeType &modeType,
		const Rf &rf,
		const Pw &pw,
		const Pri &pri,
		const Scan &scan,
		const Erp &erp)
		: m_modeCode(modeCode)
		, m_rf(rf)
		, m_pw(pw)
		, m_pri(pri)
		, m_scan(scan)
		, m_erp(erp)
		, m_modeType(modeType)
	{
	}

	Radar_Mode::~Radar_Mode(void)
	{
	}
	const std::string & Radar_Mode::getModeCode(void) const
	{
		return m_modeCode;
	}
	const ModeType & Radar_Mode::getModeType(void) const
	{
		return m_modeType;
	}

	Rf & Radar_Mode::getRf(void)
	{
		return m_rf;
	}

	Pw & Radar_Mode::getPw(void)
	{
		return m_pw;
	}

	Pri & Radar_Mode::getPri(void)
	{
		return m_pri;
	}

	Scan & Radar_Mode::getScan(void)
	{
		return m_scan;
	}

	Erp & Radar_Mode::getErp(void)
	{
		return m_erp;
	}

	void Radar_Mode::setModeCode(const std::string & modeCode)
	{
		m_modeCode = modeCode;
	}

	void Radar_Mode::setModeType(const ModeType & modeType)
	{
		m_modeType = modeType;
	}

	void Radar_Mode::setRf(const Rf & rf)
	{
		m_rf = rf;
	}

	void Radar_Mode::setPw(const Pw & pw)
	{
		m_pw = pw;
	}

	void Radar_Mode::setPri(const Pri & pri)
	{
		m_pri.setPriMax(pri.getPriMax());
		m_pri.setPriMin(pri.getPriMin());
		m_pri.setPriType(pri.getPriType());
		m_pri.getPriValues();
	}

	void Radar_Mode::setScan(const Scan & scan)
	{
		m_scan = scan;
	}

	void Radar_Mode::setErp(const Erp & erp)
	{
		m_erp = erp;
	}

	/***************************Emitter*********************************/
	//由于默认构造函数尚未进行RadarMode值初始化，所以调用默认构造后应尽快完成RadarMode值初始化操作
	Emitter::Emitter(void)
	{
	}

	Emitter::Emitter(const std::string &name,
		std::shared_ptr<Radar_Mode>& ptrRadarMode)
		: m_name(name)
		, m_ptrRadarMode{ ptrRadarMode }
	{
	}

	Emitter::Emitter(const std::string& name,
		std::vector<std::shared_ptr<Radar_Mode>>& ptrRadarMode)
		: m_name(name)
		, m_ptrRadarMode( ptrRadarMode )
	{
	}

	Emitter::~Emitter(void)
	{
	}

	const std::string& Emitter::getName(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_name;
	}

	const std::shared_ptr<Radar_Mode> Emitter::getRadarMode(unsigned int valueOrder) const
	{
		// TODO: 在此处插入 return 语句
		assert(valueOrder>= m_ptrRadarMode.size());
		if (valueOrder<m_ptrRadarMode.size())
		{
			return m_ptrRadarMode[valueOrder];
		}
		throw Error("can't return this value (doesn't exist)");
	}

	void Emitter::addRadarMode(const std::shared_ptr<Radar_Mode> ptr_radarmode)
	{
		m_ptrRadarMode.push_back(ptr_radarmode);
	}

	bool Emitter::insertRadarMode(unsigned int pos, std::shared_ptr<Radar_Mode> ptr_radarmode)
	{
		assert(pos>m_ptrRadarMode.size());
		if (pos<=m_ptrRadarMode.size())
		{
			m_ptrRadarMode.insert(m_ptrRadarMode.begin() + pos, ptr_radarmode);
			return true;
		}
		return false;
	}

	bool Emitter::deleteRadarMode(unsigned int pos)
	{
		assert(pos>=m_ptrRadarMode.size());
		if (pos < m_ptrRadarMode.size())
		{
			m_ptrRadarMode.erase(m_ptrRadarMode.begin() + pos);
			return true;
		}
		return false;
	}

	void Emitter::setName(const std::string & name)
	{
		m_name = name;
	}
	
	/*********************Weapon*********************************/
	Weapon::Weapon(void)
	{
	}

	Weapon::Weapon(const std::string& name,
		const unsigned long& cepr,
		const unsigned long& weaponAreaCoverage)
		:m_name(name)
		,m_cepr(cepr)
		,m_weaponAreaCoverage(weaponAreaCoverage)
	{
	}

	Weapon::~Weapon(void)
	{
	}

	const std::string & Weapon::getName(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_name;
	}

	const unsigned long & Weapon::getCEPR(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_cepr;
	}

	const unsigned long & Weapon::getWeaponAreaCoverage(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_weaponAreaCoverage;
	}

	void Weapon::setName(const std::string & name)
	{
		m_name = name;
	}

	void Weapon::setCEPR(const unsigned long &cepr)
	{
		m_cepr = cepr;
	}

	void Weapon::setWeaponAreaCoverage(const unsigned long &weaponAreaCoverage)
	{
		m_weaponAreaCoverage = weaponAreaCoverage;
	}

	/***********************Site*********************************/
	Site::Site(void)
	{
	}

	Site::Site(const std::string &name,
		const double &altitude,
		const double &latitude,
		const double &longitude)
		:m_name(name)
		,m_altitude(altitude)
		,m_latitude(latitude)
		,m_longitude(longitude)
	{
	}

	Site::~Site(void)
	{
	}

	const std::string & Site::getName(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_name;
	}

	const double & Site::getAltitude(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_altitude;
	}

	const double & Site::getLatitude(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_latitude;
	}

	const double & Site::getLongitude(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_longitude;
	}

	void Site::setName(const std::string &name)
	{
		m_name = name;
	}

	void Site::setAltitude(const double &altitude)
	{
		m_altitude = altitude;
	}

	void Site::setLatitude(const double &latitude)
	{
		m_latitude = latitude;
	}

	void Site::setLongitude(const double &longitude)
	{
		m_longitude = longitude;
	}

	/*******************Point*******************************/
	Point::Point(void)
	{
	}

	Point::Point(const double &altitude,
		const double &latitude,
		const double &longitude,
		const double &tmin,
		const double &tmax)
		:m_altitude(altitude)
		,m_latitude(latitude)
		,m_longitude(longitude)
		,m_tmin(tmin)
		,m_tmax(tmax)
	{
	}

	Point::~Point(void)
	{
	}

	const double & Point::getAltitude(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_altitude;
	}

	const double & Point::getLatitude(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_latitude;
	}

	const double & Point::getLongitude(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_longitude;
	}

	const double & Point::getTmin(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_tmin;
	}

	const double & Point::getTmax(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_tmax;
	}

	void Point::setAltitude(const double &altitude)
	{
		m_altitude = altitude;
	}

	void Point::setLatitude(const double &latitude)
	{
		m_latitude = latitude;
	}

	void Point::setLongitude(const double &longitude)
	{
		m_longitude = longitude;
	}

	void Point::setTmin(const double &tmin)
	{
		m_tmin = tmin;
	}

	void Point::setTmax(const double &tmax)
	{
		m_tmax = tmax;
	}

	/*******************Mission********************************/
	Mission::Mission(void)
	{
	}

	Mission::Mission(const MissionType &missionType,
		const Point &startPoint,
		const Point &endPoint,
		const std::vector<Point>&targetPoint)
		:m_type(missionType)
		,m_startPoint(startPoint)
		,m_endPoint(endPoint)
		,m_targetPoints(targetPoint)
	{
	}

	Mission::Mission(const MissionType &missionType,
		const Point &startPoint,
		const Point &endPoint,
		const Point &targetPoint)
		:m_type(missionType)
		, m_startPoint(startPoint)
		, m_endPoint(endPoint)
		, m_targetPoints{ targetPoint }
	{
	}

	//此构造函数应该在MissionType为Support时才用此构造函数，但一如前面所说，不保证安全性
	Mission::Mission(const MissionType &missionType,
		const Point &startPoint,
		const Point &endPoint)
		:m_type(missionType)
		,m_startPoint(startPoint)
		,m_endPoint(endPoint)
	{
	}

	Mission::~Mission(void)
	{
	}

	const MissionType & Mission::getMissionType(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_type;
	}

	Point & Mission::getStartPoint(void)
	{
		// TODO: 在此处插入 return 语句
		return m_startPoint;
	}

	Point & Mission::getEndPoint(void)
	{
		// TODO: 在此处插入 return 语句
		return m_endPoint;
	}

	bool Mission::isTargetPointEmpty(void)
	{
		return m_targetPoints.empty()?true:false;
	}

	Point & Mission::getTargetPoint(unsigned int pointOrder)
	{
		// TODO: 在此处插入 return 语句
		assert(pointOrder >= m_targetPoints.size());
		if (pointOrder<m_targetPoints.size())
		{
			return m_targetPoints[pointOrder];
		}
		throw Error("can't return this value (doesn't exist)");
	}

	//请注意，当使用默认构造函数时，添加第一个类对象时，不应该直接使用add函数，
	//因为默认构造已经初始化了一个随机的对象在容器中，此时应该对这个初始化对象进行编辑使其成为待添加的对象。
	void Mission::addTargetPoint(const Point &targetPoint)
	{
		m_targetPoints.push_back(targetPoint);
	}

	bool Mission::insertTargetPoint(unsigned int pos, const Point &targetPoint)
	{
		assert(pos > m_targetPoints.size());
		if (pos <= m_targetPoints.size())
		{
			m_targetPoints.insert(m_targetPoints.begin()+pos,targetPoint);
			return true;
		}
		return false;
	}

	bool Mission::deleteTargetPoint(unsigned int pos)
	{
		assert(pos>=m_targetPoints.size());
		if (pos<m_targetPoints.size())
		{
			m_targetPoints.erase(m_targetPoints.begin() + pos);
			return true;
		}
		return false;
	}

	void Mission::setMissionType(const MissionType &missionType)
	{
		m_type = missionType;
	}

	void Mission::setStartPoint(const Point &startPoint)
	{
		m_startPoint.setAltitude(startPoint.getAltitude());
		m_startPoint.setLatitude(startPoint.getLatitude());
		m_startPoint.setLongitude(startPoint.getLongitude());
		m_startPoint.setTmax(startPoint.getTmax());
		m_startPoint.setTmin(startPoint.getTmin());
	}

	void Mission::setEndPoint(const Point &endPoint)
	{
		m_endPoint.setAltitude(endPoint.getAltitude());
		m_endPoint.setLatitude(endPoint.getLatitude());
		m_endPoint.setLongitude(endPoint.getLongitude());
		m_endPoint.setTmax(endPoint.getTmax());
		m_endPoint.setTmin(endPoint.getTmin());
	}

}