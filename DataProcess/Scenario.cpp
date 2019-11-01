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

	std::vector<Rf_values>& Rf::getRfValues(void)
	{
		// TODO: 在此处插入 return 语句
		return m_values;
	}

	bool Rf::isValuesEmpty()
	{
		return m_values.empty() ? true : false;
	}

	Rf_values & Rf::getRfValue(unsigned int valueOrder)
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

	void Rf::setRfValues(const std::vector<Rf_values>&rfValues)
	{
		m_values = rfValues;
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

	std::vector<Pw_values>& Pw::getPwValues(void)
	{
		// TODO: 在此处插入 return 语句
		return m_values;
	}

	bool Pw::isValuesEmpty()
	{
		return m_values.empty() ? true : false;
	}

	Pw_values & Pw::getPwValue(unsigned int valueOrder)
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

	void Pw::setPwValues(const std::vector<Pw_values>&pwValues)
	{
		m_values = pwValues;
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

	//这里Rf,Pw,Pri的方法中不在用const修饰是考虑到其类成员函数中的
	//getValues(void)返回值为非常量应用，这里用const修饰Rf类对象
	//的应用会发生常量值与非常量属性值不匹配的情况，后续在深入整理
	void Radar_Mode::setRf(Rf & rf)
	{
		m_rf=rf;
		// m_rf.setRfValues(rf.getRfValues());
		
	}
	void Radar_Mode::setPw(Pw & pw)
	{
		m_pw = pw;
	}
	void Radar_Mode::setPri(Pri & pri)
	{
		m_pri=pri;
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

	std::vector<std::shared_ptr<Radar_Mode>>& Emitter::getRadarModes(void)
	{
		// TODO: 在此处插入 return 语句
		return m_ptrRadarMode;
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

	void Emitter::setRadarModes(std::vector<std::shared_ptr<Radar_Mode>>&ptrRadarModes)
	{
		m_ptrRadarMode = ptrRadarModes;
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

	std::vector<Point>& Mission::getTargetPoint(void)
	{
		// TODO: 在此处插入 return 语句
		return m_targetPoints;
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
		m_startPoint=startPoint;
	}

	void Mission::setEndPoint(const Point &endPoint)
	{
		m_endPoint=endPoint;
	}

	void Mission::setTargetPoint(const std::vector<Point>& targetPoints)
	{
		m_targetPoints = targetPoints;
	}

	/***********************OwnPlatform************************************/
	OwnPlatform::OwnPlatform(void)
	{
	}

	OwnPlatform::OwnPlatform(const std::string &name,
		const OwnPlatformType &ownPlatformType,
		const double &maxAcceleration,
		const double &maxDeceleration,
		const double &maxClimbRate,
		const double &maxDiveRate,
		const double &maxSpeed,
		const double &maxTurnRadius,
		const Mission &mission)
		:m_name(name)
		,m_type(ownPlatformType)
		,m_maxAcceleration(maxAcceleration)
		,m_maxDeceleration(maxDeceleration)
		,m_maxClimbRate(maxClimbRate)
		,m_maxDiveRate(maxDiveRate)
		,m_maxSpeed(maxSpeed)
		,m_maxTurnRadius(maxTurnRadius)
		,m_mission(mission)
	{

	}

	OwnPlatform::~OwnPlatform(void)
	{
	}

	const std::string & OwnPlatform::getName(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_name;
	}

	const OwnPlatformType & OwnPlatform::getType(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_type;
	}

	const double & OwnPlatform::getMaxAcceleration(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_maxAcceleration;
	}

	const double & OwnPlatform::getMaxDeceleration(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_maxDeceleration;
	}

	const double & OwnPlatform::getMaxClimbRate(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_maxClimbRate;
	}

	const double & OwnPlatform::getMaxDiveRate(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_maxDiveRate;
	}

	const double & OwnPlatform::getMaxSpeed(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_maxSpeed;
	}

	const double & OwnPlatform::getMaxTurnRadius(void) const
	{
		// TODO: 在此处插入 return 语句
		return m_maxTurnRadius;
	}

	Mission & OwnPlatform::getMission(void)
	{
		// TODO: 在此处插入 return 语句
		return m_mission;
	}

	void OwnPlatform::setName(const std::string &name)
	{
		m_name = name;
	}

	void OwnPlatform::setType(const OwnPlatformType &ownPlatformType)
	{
		m_type = ownPlatformType;
	}

	void OwnPlatform::setMaxAcceleration(const double &maxAcceleration)
	{
		m_maxAcceleration = maxAcceleration;
	}

	void OwnPlatform::setMaxDeceleration(const double &maxDeceleration)
	{
		m_maxDeceleration = maxDeceleration;
	}

	void OwnPlatform::setMaxClimbRate(const double &maxClimbRate)
	{
		m_maxClimbRate = maxClimbRate;
	}

	void OwnPlatform::setMaxDiveRate(const double &maxDiveRate)
	{
		m_maxDiveRate = maxDiveRate;
	}

	void OwnPlatform::setMaxSpeed(const double &maxSpeed)
	{
		m_maxSpeed = maxSpeed;
	}

	void OwnPlatform::setMaxTurnRadius(const double &maxTurnRadius)
	{
		m_maxTurnRadius = maxTurnRadius;
	}

	void OwnPlatform::setMission(const Mission &mission)
	{
		m_mission = mission;
	}

	/****************************Esm***************************/
	Esm::Esm(void)
	{
	}

	Esm::Esm(const std::string &name,
		const double &dwellFreqResolution,
		const unsigned int &tuningStep,
		const unsigned long &rfCovMin,
		const unsigned long &rfCovMax,
		const unsigned int &numPulsesAcquisition,
		const unsigned int &numPulsesAlarm)
		:m_name(name)
		,m_dwellFreqResolution(dwellFreqResolution)
		,m_tuningStep(tuningStep)
		,m_rfCovMin(rfCovMin)
		,m_rfCovMax(rfCovMax)
		,m_numPulsesAcquisition(numPulsesAcquisition)
		,m_numPulsesAlarm(numPulsesAlarm)
	{
	}

	Esm::~Esm(void)
	{
	}

	const std::string & Esm::getName(void)
	{
		// TODO: 在此处插入 return 语句
		return m_name;
	}

	const double & Esm::getDwellFreqResolution(void)
	{
		// TODO: 在此处插入 return 语句
		return m_dwellFreqResolution;
	}

	const unsigned int & Esm::getTuningStep(void)
	{
		// TODO: 在此处插入 return 语句
		return m_tuningStep;
	}

	const unsigned long & Esm::getRfCovMin(void)
	{
		// TODO: 在此处插入 return 语句
		return m_rfCovMin;
	}

	const unsigned long & Esm::getRfCovMax(void)
	{
		// TODO: 在此处插入 return 语句
		return m_rfCovMax;
	}

	const unsigned int & Esm::getNumPulsesAcquisition(void)
	{
		// TODO: 在此处插入 return 语句
		return m_numPulsesAcquisition;
	}

	const unsigned int & Esm::getNumPulsesAlarm(void)
	{
		// TODO: 在此处插入 return 语句
		return m_numPulsesAlarm;
	}

	void Esm::setName(const std::string &name)
	{
		m_name = name;
	}

	void Esm::setDwellFreqResolution(const double &dwellFreqResolution)
	{
		m_dwellFreqResolution = dwellFreqResolution;
	}

	void Esm::setTuningStep(const int &tuningStep)
	{
		m_tuningStep = tuningStep;
	}

	void Esm::setRfCovMin(const long &rfCovMin)
	{
		m_rfCovMin = rfCovMin;
	}

	void Esm::setRfCovMax(const long &rfCovMax)
	{
		m_rfCovMax = rfCovMax;
	}

	void Esm::setNumPulsesAcquisition(const int &numPulsesAcquisition)
	{
		m_numPulsesAcquisition = numPulsesAcquisition;
	}

	void Esm::setNumPulsesAlarm(const int &numPulsesAlarm)
	{
		m_numPulsesAlarm = numPulsesAlarm;
	}

	/********************Ecm********************************/
	Ecm::Ecm(void)
	{
	}

	Ecm::Ecm(const std::string &name,
		const unsigned long &pt,
		const unsigned int &gain,
		const unsigned long &rfmin,
		const unsigned long &rfmax,
		const Tech& techName)
		:m_name(name)
		, m_pt(pt)
		, m_gain(gain)
		, m_rfMin(rfmin)
		, m_rfMax(rfmax)
		, m_techName{ techName }
	{
	}

	Ecm::Ecm(const std::string &name,
		const unsigned long &pt,
		const unsigned int &gain,
		const unsigned long &rfmin,
		const unsigned long &rfmax,
		const std::vector<Tech>&techName) 
		:m_name(name)
		,m_pt(pt)
		,m_gain(gain)
		,m_rfMin(rfmin)
		,m_rfMax(rfmax)
		,m_techName(techName)
	{
	}

	Ecm::~Ecm(void)
	{
	}

	const std::string & Ecm::getName(void)
	{
		// TODO: 在此处插入 return 语句
		return m_name;
	}

	const unsigned long & Ecm::getPt(void)
	{
		// TODO: 在此处插入 return 语句
		return m_pt;
	}

	const unsigned int & Ecm::getGain(void)
	{
		// TODO: 在此处插入 return 语句
		return m_gain;
	}

	const unsigned long & Ecm::getRfMin(void)
	{
		// TODO: 在此处插入 return 语句
		return m_rfMin;
	}

	const unsigned long & Ecm::getRfMax(void)
	{
		// TODO: 在此处插入 return 语句
		return m_rfMax;
	}

	std::vector<Tech>& Ecm::getTechs(void)
	{
		// TODO: 在此处插入 return 语句
		return m_techName;
	}

	bool Ecm::isTechEmpty(void)
	{
		return m_techName.size()?true:false;
	}

	const Tech & Ecm::getTech(const unsigned int & order)
	{
		// TODO: 在此处插入 return 语句
		assert(order>=m_techName.size());
		if (order<m_techName.size())
		{
			return m_techName[order];
		}
		throw Error("can't return this value (doesn't exist)");
	}

	void Ecm::addTech(const Tech &tech)
	{
		m_techName.push_back(tech);
	}

	bool Ecm::setTech(const unsigned int & pos, const Tech &tech)
	{
		assert(pos>=m_techName.size());
		if (pos<m_techName.size())
		{
			m_techName[pos] = tech;
			return true;
		}
		return false;
	}

	bool Ecm::insertTech(const unsigned int & pos, const Tech &tech)
	{
		assert(pos > m_techName.size());
		if (pos<=m_techName.size())
		{
			m_techName.insert(m_techName.begin()+pos,tech);
			return true;
		}
		return false;
	}

	bool Ecm::deleteTech(const unsigned int & pos)
	{
		assert(pos >= m_techName.size());
		if (pos<m_techName.size())
		{
			m_techName.erase(m_techName.begin()+pos);
			return true;
		}
		return false;
	}

	void Ecm::setName(const std::string &name)
	{
		m_name = name;
	}

	void Ecm::setPt(const unsigned long &pt)
	{
		m_pt = pt;
	}

	void Ecm::setGain(const unsigned int &gain)
	{
		m_gain = gain;
	}

	void Ecm::setRfMin(const unsigned long &rfMin)
	{
		m_rfMin = rfMin;
	}

	void Ecm::setRfMax(const unsigned long &rfMax)
	{
		m_rfMax = rfMax;
	}

	void Ecm::setTechs(const std::vector<Tech>& techs)
	{
		m_techName = techs;
	}

}