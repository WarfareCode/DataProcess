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
#include<memory>
#include<type_traits>
#include<cassert>

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
		Scenario(std::shared_ptr<Vertex> ,
			std::shared_ptr<Platform> ,
			std::shared_ptr<Emitter> ,
			std::shared_ptr<Weapon> ,
			std::shared_ptr<Site> ,
			std::shared_ptr<OwnPlatform> ,
			std::shared_ptr<Esm> ,
			std::shared_ptr<Ecm> ,
			std::shared_ptr<Route> ,
			std::shared_ptr<EsmStrategy> ,
			std::shared_ptr<EcmStrategy> ,
			PlatformSiteRelation& ,
			PlatformEmitterRelation& ,
			PlatformWeaponRelation& ,
			OwnPlatformEsmRelation& ,
			EsmEsmStrategyRelation& ,
			OwnPlatformEcmRelation& ,
			EcmEcmStrategyRelation& ,
			OwnPlatformRouteRelation& );

		Scenario(std::vector<std::shared_ptr<Vertex>>& ,
			std::vector<std::shared_ptr<Platform>>& ,
			std::vector<std::shared_ptr<Emitter>>& ,
			std::vector<std::shared_ptr<Weapon>>& ,
			std::vector<std::shared_ptr<Site>>& ,
			std::vector<std::shared_ptr<OwnPlatform>>& ,
			std::vector<std::shared_ptr<Esm>>& ,
			std::vector<std::shared_ptr<Ecm>>& ,
			std::vector<std::shared_ptr<Route>>& ,
			std::vector<std::shared_ptr<EsmStrategy>>& ,
			std::vector<std::shared_ptr<EcmStrategy>>& ,
			std::vector<PlatformSiteRelation>& ,
			std::vector<PlatformEmitterRelation>& ,
			std::vector<PlatformWeaponRelation>& ,
			std::vector<OwnPlatformEsmRelation>& ,
			std::vector<EsmEsmStrategyRelation>& ,
			std::vector<OwnPlatformEcmRelation>& ,
			std::vector<EcmEcmStrategyRelation>& ,
			std::vector<OwnPlatformRouteRelation>& );
		~Scenario(void);

		template <typename T>
		bool isEmpty(void)
		{
			if (std::is_same<T , Vertex>::value) return m_vertex.empty() ? true : false;
			if (std::is_same<T , Platform>::value) return m_ptrPlatform.empty() ? true : false;
			if (std::is_same<T , Emitter>::value) return m_ptrEmitter.empty() ? true : false;
			if (std::is_same<T , Weapon>::value) return m_ptrWeapon.empty() ? true : false;
			if (std::is_same<T , Site>::value) return m_ptrSite.empty() ? true : false;
			if (std::is_same<T , OwnPlatform>::value) return m_ptrOwnPlatform.empty() ? true : false;
			if (std::is_same<T , Esm>::value) return m_ptrEsm.empty() ? true : false;
			if (std::is_same<T , Ecm>::value) return m_ptrEcm.empty() ? true : false;
			if (std::is_same<T , Route>::value) return m_ptrRoute.empty() ? true : false;
			if (std::is_same<T , EsmStrategy>::value) return m_ptrEsmStrategy.empty() ? true : false;
			if (std::is_same<T , EcmStrategy>::value) return m_ptrEcmStrategy.empty() ? true : false;

			if (std::is_same<T , PlatformSiteRelation>::value) return m_PlatformSiteRelation.empty() ? true : false;
			if (std::is_same<T , PlatformEmitterRelation>::value) return m_PlatformEmitterRelation.empty() ? true : false;
			if (std::is_same<T , PlatformWeaponRelation>::value) return m_PlatformWeaponRelation.empty() ? true : false;
			if (std::is_same<T , OwnPlatformEsmRelation>::value) return m_OwnPlatformEsmRelation.empty() ? true : false;
			if (std::is_same<T , EsmEsmStrategyRelation>::value) return m_EsmEsmStrategyRelation.empty() ? true : false;
			if (std::is_same<T , OwnPlatformEcmRelation>::value) return m_OwnPlatformEcmRelation.empty() ? true : false;
			if (std::is_same<T , EcmEcmStrategyRelation>::value) return m_EcmEcmStrategyRelation.empty() ? true : false;
			if (std::is_same<T , OwnPlatformRouteRelation>::value) return m_OwnPlatformRouteRelation.empty() ? true : false;
		}
		
		//get pointer of typename
		template<typename T>
		std::vector<std::shared_ptr<T>>& getAllPtr(void)
		{
			if (std::is_same<T , Vertex>::value) return m_vertex;

			if (std::is_same<T , Platform>::value) return m_ptrPlatform;
			
			if (std::is_same<T , Emitter>::value) return m_ptrEmitter;
			
			if (std::is_same<T , Weapon>::value) return m_ptrWeapon;
			
			if (std::is_same<T , Site>::value) return m_ptrSite;
			
			if (std::is_same<T , OwnPlatform>::value) return m_ptrOwnPlatform;
			
			if (std::is_same<T , Esm>::value) return m_ptrEsm;
			
			if (std::is_same<T , Ecm>::value) return m_ptrEcm;
			
			if (std::is_same<T , Route>::value) return m_ptrRoute;
			
			if (std::is_same<T , EsmStrategy>::value) return m_ptrEsmStrategy;
			
			if (std::is_same<T , EcmStrategy>::value) return m_ptrEcmStrategy;
		}

		template<class T>
		std::shared_ptr<T> getPtr(const unsigned int& pos) 
		{
			using type = typename std::decay<typename T>::type;
			if (std::is_same<type,Vertex>::value)
			{
				assert(pos<m_vertex.size());
				if (pos<m_vertex.size())
				{
					return m_vertex[pos];
				}
			}
			if (std::is_same<type,Platform>::value)
			{
				assert(pos < m_ptrPlatform.size());
				if (pos < m_ptrPlatform.size())
				{
					return m_ptrPlatform[pos];
				}
			}
			if (std::is_same<T , Emitter>::value)
			{
				assert(pos < m_ptrEmitter.size());
				if (pos < m_ptrEmitter.size())
				{
					return m_ptrEmitter[pos];
				}
			}
			if (std::is_same<T , Weapon>::value)
			{
				assert(pos < m_ptrWeapon.size());
				if (pos < m_ptrWeapon.size())
				{
					return m_ptrWeapon[pos];
				}
			}
			if (std::is_same<T , Site>::value)
			{
				assert(pos < m_ptrSite.size());
				if (pos < m_ptrSite.size())
				{
					return m_ptrSite[pos];
				}
			}
			if (std::is_same<T , OwnPlatform>::value)
			{
				assert(pos < m_ptrOwnPlatform.size());
				if (pos < m_ptrOwnPlatform.size())
				{
					return m_ptrOwnPlatform[pos];
				}
			}
			if (std::is_same<T , Esm>::value)
			{
				assert(pos < m_ptrEsm.size());
				if (pos < m_ptrEsm.size())
				{
					return m_ptrEsm[pos];
				}
			}
			if (std::is_same<T , Ecm>::value)
			{
				assert(pos < m_ptrEcm.size());
				if (pos < m_ptrEcm.size())
				{
					return m_ptrEcm[pos];
				}
			}
			if (std::is_same<T , Route>::value)
			{
				assert(pos < m_ptrRoute.size());
				if (pos < m_ptrRoute.size())
				{
					return m_ptrRoute[pos];
				}
			}
			if (std::is_same<T , EsmStrategy>::value)
			{
				assert(pos < m_ptrEsmStrategy.size());
				if (pos < m_ptrEsmStrategy.size())
				{
					return m_ptrEsmStrategy[pos];
				}
			}
			if (std::is_same<T , EcmStrategy>::value)
			{
				assert(pos < m_ptrEcmStrategy.size());
				if (pos < m_ptrEcmStrategy.size())
				{
					return m_ptrEcmStrategy[pos];
				}
			}
			throw Error("can't return this value (doesn't exist)");
		}

		//set pointer of all entities
		template<typename T>
		void setAllPtrs(std::vector<std::shared_ptr<T>>& ptr2AllEntities)
		{
			if (std::is_same<T , Vertex>::value) m_vertex=ptr2AllEntities;

			if (std::is_same<T , Platform>::value) m_ptrPlatform=ptr2AllEntities;

			if (std::is_same<T , Emitter>::value) m_ptrEmitter=ptr2AllEntities;

			if (std::is_same<T , Weapon>::value) m_ptrWeapon=ptr2AllEntities;

			if (std::is_same<T , Site>::value) m_ptrSite=ptr2AllEntities;

			if (std::is_same<T , OwnPlatform>::value) m_ptrOwnPlatform=ptr2AllEntities;

			if (std::is_same<T , Esm>::value) m_ptrEsm=ptr2AllEntities;

			if (std::is_same<T , Ecm>::value) m_ptrEcm=ptr2AllEntities;

			if (std::is_same<T , Route>::value) m_ptrRoute=ptr2AllEntities;

			if (std::is_same<T , EsmStrategy>::value) m_ptrEsmStrategy=ptr2AllEntities;

			if (std::is_same<T , EcmStrategy>::value) m_ptrEcmStrategy=ptr2AllEntities;
		}

		//set/modify pointer of entity
		template<typename T>
		bool setPtr(const unsigned int& pos, std::shared_ptr<T> ptr2Entity)
		{
			if (std::is_same<T , Vertex>::value)
			{
				assert(pos < m_vertex.size());
				if (pos < m_vertex.size())
				{
					m_vertex[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , Platform>::value)
			{
				assert(pos < m_ptrPlatform.size());
				if (pos < m_ptrPlatform.size())
				{
					m_ptrPlatform[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , Emitter>::value)
			{
				assert(pos < m_ptrEmitter.size());
				if (pos < m_ptrEmitter.size())
				{
					m_ptrEmitter[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , Weapon>::value)
			{
				assert(pos < m_ptrWeapon.size());
				if (pos < m_ptrWeapon.size())
				{
					m_ptrWeapon[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , Site>::value)
			{
				assert(pos < m_ptrSite.size());
				if (pos < m_ptrSite.size())
				{
					m_ptrSite[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , OwnPlatform>::value)
			{
				assert(pos < m_ptrOwnPlatform.size());
				if (pos < m_ptrOwnPlatform.size())
				{
					m_ptrOwnPlatform[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , Esm>::value)
			{
				assert(pos < m_ptrEsm.size());
				if (pos < m_ptrEsm.size())
				{
					m_ptrEsm[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , Ecm>::value)
			{
				assert(pos < m_ptrEcm.size());
				if (pos < m_ptrEcm.size())
				{
					m_ptrEcm[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , Route>::value)
			{
				assert(pos < m_ptrRoute.size());
				if (pos < m_ptrRoute.size())
				{
					m_ptrRoute[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , EsmStrategy>::value)
			{
				assert(pos < m_ptrEsmStrategy.size());
				if (pos < m_ptrEsmStrategy.size())
				{
					m_ptrEsmStrategy[pos] = ptr2Entity;
					return true;
				}
			}
			if (std::is_same<T , EcmStrategy>::value)
			{
				assert(pos < m_ptrEcmStrategy.size());
				if (pos < m_ptrEcmStrategy.size())
				{
					m_ptrEcmStrategy[pos] = ptr2Entity;
					return true;
				}
			}
			return false;
		}

		//insert pointer of entity
		template<typename T>
		bool insertPtr(const unsigned int& pos, std::shared_ptr<T> ptr2Entity)
		{
			if (std::is_same<T , Vertex>::value)
			{
				assert(pos <= m_vertex.size());
				if (pos <= m_vertex.size())
				{
					m_vertex.insert(m_vertex.begin() + pos, ptr2Entity);;
					return true;
				}
			}
			if (std::is_same<T , Platform>::value)
			{
				assert(pos <= m_ptrPlatform.size());
				if (pos <= m_ptrPlatform.size())
				{
					m_ptrPlatform.insert(m_ptrPlatform.begin() + pos, ptr2Entity);
					return true;
				}
			}
			if (std::is_same<T , Emitter>::value)
			{
				assert(pos <= m_ptrEmitter.size());
				if (pos <= m_ptrEmitter.size())
				{
					m_ptrEmitter.insert(m_ptrEmitter.begin() + pos, ptr2Entity);
					return true;
				}
			}
			if (std::is_same<T , Weapon>::value)
			{
				assert(pos <= m_ptrWeapon.size());
				if (pos <= m_ptrWeapon.size())
				{
					m_ptrWeapon.insert(m_ptrWeapon.begin() + pos, ptr2Entity);
					return true;
				}
			}
			if (std::is_same<T , Site>::value)
			{
				assert(pos <= m_ptrSite.size());
				if (pos <= m_ptrSite.size())
				{
					m_ptrSite.insert(m_ptrSite.begin() + pos, ptr2Entity);
					return true;
				}
			}
			if (std::is_same<T , OwnPlatform>::value)
			{
				assert(pos <= m_ptrOwnPlatform.size());
				if (pos <= m_ptrOwnPlatform.size())
				{
					m_ptrOwnPlatform.insert(m_ptrOwnPlatform.begin() + pos, ptr2Entity);
					return true;
				}
			}
			if (std::is_same<T , Esm>::value)
			{
				assert(pos <= m_ptrEsm.size());
				if (pos <= m_ptrEsm.size())
				{
					m_ptrEsm.insert(m_ptrEsm.begin() + pos, ptr2Entity);
					return true;
				}
			}
			if (std::is_same<T , Ecm>::value)
			{
				assert(pos <= m_ptrEcm.size());
				if (pos <= m_ptrEcm.size())
				{
					m_ptrEcm.insert(m_ptrEcm.begin() + pos, ptr2Entity);
					return true;
				}
			}
			if (std::is_same<T , Route>::value)
			{
				assert(pos <= m_ptrRoute.size());
				if (pos <= m_ptrRoute.size())
				{
					m_ptrRoute.insert(m_ptrRoute.begin() + pos, ptr2Entity);
					return true;
				}
			}
			if (std::is_same<T , EsmStrategy>::value)
			{
				assert(pos <= m_ptrEsmStrategy.size());
				if (pos <= m_ptrEsmStrategy.size())
				{
					m_ptrEsmStrategy.insert(m_ptrEsmStrategy.begin() + pos, ptr2Entity);
					return true;
				}
			}
			if (std::is_same<T , EcmStrategy>::value)
			{
				assert(pos <= m_ptrEcmStrategy.size());
				if (pos <= m_ptrEcmStrategy.size())
				{
					m_ptrEcmStrategy.insert(m_ptrEcmStrategy.begin() + pos, ptr2Entity);
					return true;
				}
			}
			return false;
		}

		//add pointer of all entities
		template<typename T>
		void addPtr(std::shared_ptr<T> ptr2Entitiy)
		{
			if (std::is_same<T , Vertex>::value) m_vertex.push_back(ptr2Entitiy);
			if (std::is_same<T , Platform>::value) m_ptrPlatform.push_back(ptr2Entitiy);
			if (std::is_same<T , Emitter>::value) m_ptrEmitter.push_back(ptr2Entitiy);
			if (std::is_same<T , Weapon>::value) m_ptrWeapon.push_back(ptr2Entitiy);
			if (std::is_same<T , Site>::value) m_ptrSite.push_back(ptr2Entitiy);
			if (std::is_same<T , OwnPlatform>::value) m_ptrOwnPlatform.push_back(ptr2Entitiy);
			if (std::is_same<T , Esm>::value) m_ptrEsm.push_back(ptr2Entitiy);
			if (std::is_same<T , Ecm>::value) m_ptrEcm.push_back(ptr2Entitiy);
			if (std::is_same<T , Route>::value) m_ptrRoute.push_back(ptr2Entitiy);
			if (std::is_same<T , EsmStrategy>::value) m_ptrEsmStrategy.push_back(ptr2Entitiy);
			if (std::is_same<T , EcmStrategy>::value) m_ptrEcmStrategy.push_back(ptr2Entitiy);
		}

		//delete pointer of entity
		template<typename T>
		bool deletePtr(const unsigned int& pos)
		{
			if (std::is_same<T , Vertex>::value)
			{
				assert(pos < m_vertex.size());
				if (pos < m_vertex.size())
				{
					m_vertex.erase(m_vertex.begin()+pos);
					return true;
				}
			}
			if (std::is_same<T , Platform>::value)
			{
				assert(pos < m_ptrPlatform.size());
				if (pos < m_ptrPlatform.size())
				{
					m_ptrPlatform.erase(m_ptrPlatform.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , Emitter>::value)
			{
				assert(pos < m_ptrEmitter.size());
				if (pos < m_ptrEmitter.size())
				{
					m_ptrEmitter.erase(m_ptrEmitter.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , Weapon>::value)
			{
				assert(pos < m_ptrWeapon.size());
				if (pos < m_ptrWeapon.size())
				{
					m_ptrWeapon.erase(m_ptrWeapon.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , Site>::value)
			{
				assert(pos < m_ptrSite.size());
				if (pos < m_ptrSite.size())
				{
					m_ptrSite.erase(m_ptrSite.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , OwnPlatform>::value)
			{
				assert(pos < m_ptrOwnPlatform.size());
				if (pos < m_ptrOwnPlatform.size())
				{
					m_ptrOwnPlatform.erase(m_ptrOwnPlatform.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , Esm>::value)
			{
				assert(pos < m_ptrEsm.size());
				if (pos < m_ptrEsm.size())
				{
					m_ptrEsm.erase(m_ptrEsm.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , Ecm>::value)
			{
				assert(pos < m_ptrEcm.size());
				if (pos < m_ptrEcm.size())
				{
					m_ptrEcm.erase(m_ptrEcm.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , Route>::value)
			{
				assert(pos < m_ptrRoute.size());
				if (pos < m_ptrRoute.size())
				{
					m_ptrRoute.erase(m_ptrRoute.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , EsmStrategy>::value)
			{
				assert(pos < m_ptrEsmStrategy.size());
				if (pos < m_ptrEsmStrategy.size())
				{
					m_ptrEsmStrategy.erase(m_ptrEsmStrategy.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , EcmStrategy>::value)
			{
				assert(pos < m_ptrEcmStrategy.size());
				if (pos < m_ptrEcmStrategy.size())
				{
					m_ptrEcmStrategy.erase(m_ptrEcmStrategy.begin() + pos);
					return true;
				}
			}
			return false;
		}

		//std::shared_ptr<Vertex> getPtr2Vertex(const unsigned int& pos);
		//std::shared_ptr<Platform> getPtr2Platform(const unsigned int& pos);
		//std::shared_ptr<Emitter> getPtr2Emitter(const unsigned int& pos);
		//std::shared_ptr<Weapon> getPtr2Weapon(const unsigned int& pos);
		//std::shared_ptr<Site> getPtr2Site(const unsigned int& pos);
		//std::shared_ptr<OwnPlatform> getPtr2OwnPlatform(const unsigned int& pos);
		//std::shared_ptr<Esm> getPtr2Esm(const unsigned int& pos);
		//std::shared_ptr<Ecm> getPtr2Ecm(const unsigned int& pos);
		//std::shared_ptr<Route> getPtr2Route(const unsigned int& pos);
		//std::shared_ptr<EsmStrategy> getPtr2EsmStrategy(const unsigned int& pos);
		//std::shared_ptr<EcmStrategy> getPtr2EcmStrategy(const unsigned int& pos);
		
		template<typename T>
		std::vector<T>& getAllRelation(void)
		{
			if (std::is_same<T , PlatformSiteRelation>::value) return m_PlatformSiteRelation;

			if (std::is_same<T , PlatformEmitterRelation>::value) return m_PlatformEmitterRelation;

			if (std::is_same<T , PlatformWeaponRelation>::value) return m_PlatformWeaponRelation;

			if (std::is_same<T , OwnPlatformEsmRelation>::value) return m_OwnPlatformEsmRelation;

			if (std::is_same<T , EsmEsmStrategyRelation>::value) return m_EsmEsmStrategyRelation;

			if (std::is_same<T , OwnPlatformEcmRelation>::value) return m_OwnPlatformEcmRelation;

			if (std::is_same<T , EcmEcmStrategyRelation>::value) return m_EcmEcmStrategyRelation;

			if (std::is_same<T , OwnPlatformRouteRelation>::value) return m_OwnPlatformRouteRelation;
		}

		template <typename T>
		T& getRelation(const unsigned int& pos)
		{
			if (std::is_same<T , PlatformSiteRelation>::value)
			{
				assert(pos < m_PlatformSiteRelation.size());
				if (pos < m_PlatformSiteRelation.size())
				{
					return m_PlatformSiteRelation[pos];
				}
			}
			if (std::is_same<T , PlatformEmitterRelation>::value)
			{
				assert(pos < m_PlatformEmitterRelation.size());
				if (pos < m_PlatformEmitterRelation.size())
				{
					return m_PlatformEmitterRelation[pos];
				}
			}
			if (std::is_same<T , PlatformWeaponRelation>::value)
			{
				assert(pos < m_PlatformWeaponRelation.size());
				if (pos < m_PlatformWeaponRelation.size())
				{
					return m_PlatformWeaponRelation[pos];
				}
			}
			if (std::is_same<T , OwnPlatformEsmRelation>::value)
			{
				assert(pos < m_OwnPlatformEsmRelation.size());
				if (pos < m_OwnPlatformEsmRelation.size())
				{
					return m_OwnPlatformEsmRelation[pos];
				}
			}
			if (std::is_same<T , EsmEsmStrategyRelation>::value)
			{
				assert(pos < m_EsmEsmStrategyRelation.size());
				if (pos < m_EsmEsmStrategyRelation.size())
				{
					return m_EsmEsmStrategyRelation[pos];
				}
			}
			if (std::is_same<T , OwnPlatformEcmRelation>::value)
			{
				assert(pos < m_OwnPlatformEcmRelation.size());
				if (pos < m_OwnPlatformEcmRelation.size())
				{
					return m_OwnPlatformEcmRelation[pos];
				}
			}
			if (std::is_same<T , EcmEcmStrategyRelation>::value)
			{
				assert(pos < m_EcmEcmStrategyRelation.size());
				if (pos < m_EcmEcmStrategyRelation.size())
				{
					return m_EcmEcmStrategyRelation[pos];
				}
			}
			if (std::is_same<T , OwnPlatformRouteRelation>::value)
			{
				assert(pos < m_OwnPlatformRouteRelation.size());
				if (pos < m_OwnPlatformRouteRelation.size())
				{
					return m_OwnPlatformRouteRelation[pos];
				}
			}
			throw Error("can't return this value (doesn't exist)");
		}

		template<typename T>
		void setAllRelation(std::vector<T>& relations)
		{
			if (std::is_same<T , PlatformSiteRelation>::value) m_PlatformSiteRelation= relations;

			if (std::is_same<T , PlatformEmitterRelation>::value) m_PlatformEmitterRelation= relations;

			if (std::is_same<T , PlatformWeaponRelation>::value) m_PlatformWeaponRelation= relations;

			if (std::is_same<T , OwnPlatformEsmRelation>::value) m_OwnPlatformEsmRelation= relations;

			if (std::is_same<T , EsmEsmStrategyRelation>::value) m_EsmEsmStrategyRelation= relations;

			if (std::is_same<T , OwnPlatformEcmRelation>::value) m_OwnPlatformEcmRelation= relations;

			if (std::is_same<T , EcmEcmStrategyRelation>::value) m_EcmEcmStrategyRelation= relations;

			if (std::is_same<T , OwnPlatformRouteRelation>::value) m_OwnPlatformRouteRelation= relations;
		}

		template <typename T>
		bool setRelation(const unsigned int& pos, T& relation)
		{
			if (std::is_same<T , PlatformSiteRelation>::value)
			{
				assert(pos < m_PlatformSiteRelation.size());
				if (pos < m_PlatformSiteRelation.size())
				{
					m_PlatformSiteRelation[pos] = relation;
					return true;
				}
			}
			if (std::is_same<T , PlatformEmitterRelation>::value)
			{
				assert(pos < m_PlatformEmitterRelation.size());
				if (pos < m_PlatformEmitterRelation.size())
				{
					m_PlatformEmitterRelation[pos] = relation;
					return true;
				}
			}
			if (std::is_same<T , PlatformWeaponRelation>::value)
			{
				assert(pos < m_PlatformWeaponRelation.size());
				if (pos < m_PlatformWeaponRelation.size())
				{
					m_PlatformWeaponRelation[pos] = relation;
					return true;
				}
			}
			if (std::is_same<T , OwnPlatformEsmRelation>::value)
			{
				assert(pos < m_OwnPlatformEsmRelation.size());
				if (pos < m_OwnPlatformEsmRelation.size())
				{
					m_OwnPlatformEsmRelation[pos] = relation;
					return true;
				}
			}
			if (std::is_same<T , EsmEsmStrategyRelation>::value)
			{
				assert(pos < m_EsmEsmStrategyRelation.size());
				if (pos < m_EsmEsmStrategyRelation.size())
				{
					m_EsmEsmStrategyRelation[pos] = relation;
					return true;
				}
			}
			if (std::is_same<T , OwnPlatformEcmRelation>::value)
			{
				assert(pos < m_OwnPlatformEcmRelation.size());
				if (pos < m_OwnPlatformEcmRelation.size())
				{
					m_OwnPlatformEcmRelation[pos] = relation;
					return true;
				}
			}
			if (std::is_same<T , EcmEcmStrategyRelation>::value)
			{
				assert(pos < m_EcmEcmStrategyRelation.size());
				if (pos < m_EcmEcmStrategyRelation.size())
				{
					m_EcmEcmStrategyRelation[pos] = relation;
					return true;
				}
			}
			if (std::is_same<T , OwnPlatformRouteRelation>::value)
			{
				assert(pos < m_OwnPlatformRouteRelation.size());
				if (pos < m_OwnPlatformRouteRelation.size())
				{
					m_OwnPlatformRouteRelation[pos] = relation;
					return true;
				}
			}
			return false;
		}

		template <typename T>
		bool insertRelation(const unsigned int& pos, T& relation)
		{
			if (std::is_same<T , PlatformSiteRelation>::value)
			{
				assert(pos <= m_PlatformSiteRelation.size());
				if (pos <= m_PlatformSiteRelation.size())
				{
					m_PlatformSiteRelation.insert(m_PlatformSiteRelation.begin() +pos, relation);
					return true;
				}
			}
			if (std::is_same<T , PlatformEmitterRelation>::value)
			{
				assert(pos <= m_PlatformEmitterRelation.size());
				if (pos <= m_PlatformEmitterRelation.size())
				{
					m_PlatformEmitterRelation.insert(m_PlatformEmitterRelation.begin() + pos, relation);
					return true;
				}
			}
			if (std::is_same<T , PlatformWeaponRelation>::value)
			{
				assert(pos <= m_PlatformWeaponRelation.size());
				if (pos <= m_PlatformWeaponRelation.size())
				{
					m_PlatformWeaponRelation.insert(m_PlatformWeaponRelation.begin() + pos, relation);
					return true;
				}
			}
			if (std::is_same<T , OwnPlatformEsmRelation>::value)
			{
				assert(pos <= m_OwnPlatformEsmRelation.size());
				if (pos <= m_OwnPlatformEsmRelation.size())
				{
					m_OwnPlatformEsmRelation.insert(m_OwnPlatformEsmRelation.begin() + pos, relation);
					return true;
				}
			}
			if (std::is_same<T , EsmEsmStrategyRelation>::value)
			{
				assert(pos <= m_EsmEsmStrategyRelation.size());
				if (pos <= m_EsmEsmStrategyRelation.size())
				{
					m_EsmEsmStrategyRelation.insert(m_EsmEsmStrategyRelation.begin() + pos, relation);
					return true;
				}
			}
			if (std::is_same<T , OwnPlatformEcmRelation>::value)
			{
				assert(pos <= m_OwnPlatformEcmRelation.size());
				if (pos <= m_OwnPlatformEcmRelation.size())
				{
					m_OwnPlatformEcmRelation.insert(m_OwnPlatformEcmRelation.begin() + pos, relation);
					return true;
				}
			}
			if (std::is_same<T , EcmEcmStrategyRelation>::value)
			{
				assert(pos <= m_EcmEcmStrategyRelation.size());
				if (pos <= m_EcmEcmStrategyRelation.size())
				{
					m_EcmEcmStrategyRelation.insert(m_EcmEcmStrategyRelation.begin() + pos, relation);
					return true;
				}
			}
			if (std::is_same<T , OwnPlatformRouteRelation>::value)
			{
				assert(pos <= m_OwnPlatformRouteRelation.size());
				if (pos <= m_OwnPlatformRouteRelation.size())
				{
					m_OwnPlatformRouteRelation.insert(m_OwnPlatformRouteRelation.begin() + pos, relation);
					return true;
				}
			}
			return false;
		}

		template<typename T>
		void addRelation(T& relation)
		{
			if (std::is_same<T , PlatformSiteRelation>::value) m_PlatformSiteRelation.push_back(relation);

			if (std::is_same<T , PlatformEmitterRelation>::value) m_PlatformEmitterRelation.push_back(relation);

			if (std::is_same<T , PlatformWeaponRelation>::value) m_PlatformWeaponRelation.push_back(relation);

			if (std::is_same<T , OwnPlatformEsmRelation>::value) m_OwnPlatformEsmRelation.push_back(relation);

			if (std::is_same<T , EsmEsmStrategyRelation>::value) m_EsmEsmStrategyRelation.push_back(relation);

			if (std::is_same<T , OwnPlatformEcmRelation>::value) m_OwnPlatformEcmRelation.push_back(relation);

			if (std::is_same<T , EcmEcmStrategyRelation>::value) m_EcmEcmStrategyRelation.push_back(relation);

			if (std::is_same<T , OwnPlatformRouteRelation>::value) m_OwnPlatformRouteRelation.push_back(relation);
		}

		template <typename T>
		bool deleteRelation(const unsigned int& pos)
		{
			if (std::is_same<T , PlatformSiteRelation>::value)
			{
				assert(pos < m_PlatformSiteRelation.size());
				if (pos < m_PlatformSiteRelation.size())
				{
					m_PlatformSiteRelation.erase(m_PlatformSiteRelation.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , PlatformEmitterRelation>::value)
			{
				assert(pos < m_PlatformEmitterRelation.size());
				if (pos < m_PlatformEmitterRelation.size())
				{
					m_PlatformEmitterRelation.erase(m_PlatformEmitterRelation.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , PlatformWeaponRelation>::value)
			{
				assert(pos < m_PlatformWeaponRelation.size());
				if (pos < m_PlatformWeaponRelation.size())
				{
					m_PlatformWeaponRelation.erase(m_PlatformWeaponRelation.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , OwnPlatformEsmRelation>::value)
			{
				assert(pos < m_OwnPlatformEsmRelation.size());
				if (pos < m_OwnPlatformEsmRelation.size())
				{
					m_OwnPlatformEsmRelation.erase(m_OwnPlatformEsmRelation.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , EsmEsmStrategyRelation>::value)
			{
				assert(pos < m_EsmEsmStrategyRelation.size());
				if (pos < m_EsmEsmStrategyRelation.size())
				{
					m_EsmEsmStrategyRelation.erase(m_EsmEsmStrategyRelation.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , OwnPlatformEcmRelation>::value)
			{
				assert(pos < m_OwnPlatformEcmRelation.size());
				if (pos < m_OwnPlatformEcmRelation.size())
				{
					m_OwnPlatformEcmRelation.erase(m_OwnPlatformEcmRelation.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , EcmEcmStrategyRelation>::value)
			{
				assert(pos < m_EcmEcmStrategyRelation.size());
				if (pos < m_EcmEcmStrategyRelation.size())
				{
					m_EcmEcmStrategyRelation.erase(m_EcmEcmStrategyRelation.begin() + pos);
					return true;
				}
			}
			if (std::is_same<T , OwnPlatformRouteRelation>::value)
			{
				assert(pos < m_OwnPlatformRouteRelation.size());
				if (pos < m_OwnPlatformRouteRelation.size())
				{
					m_OwnPlatformRouteRelation.erase(m_OwnPlatformRouteRelation.begin() + pos);
					return true;
				}
			}
			return false;
		}

		//PlatformSiteRelation& getPlatformSiteRelation(const unsigned int& pos);
		//PlatformEmitterRelation& getPlatformEmitterRelation(const unsigned int& pos);
		//PlatformWeaponRelation& getPlatformWeaponRelation(const unsigned int& pos);
		//OwnPlatformEsmRelation& getOwnPlatformEsmRelation(const unsigned int& pos);
		//EsmEsmStrategyRelation& getEsmEsmStrategyRelation(const unsigned int& pos);
		//OwnPlatformEcmRelation& getOwnPlatformEcmRelation(const unsigned int& pos);
		//EcmEcmStrategyRelation& getEcmEcmStrategyRelation(const unsigned int& pos);
		//OwnPlatformRouteRelation& getOwnPlatformRouteRelation(const unsigned int& pos);

	private:
		std::vector<std::shared_ptr<Vertex>> m_vertex;
		//由于Platform中name数据成员为string这种可变长类型，不应直接在容器中放置类对象，而应该使用指针
		std::vector<std::shared_ptr<Platform>> m_ptrPlatform;

		std::vector<std::shared_ptr<Emitter>> m_ptrEmitter;
		std::vector<std::shared_ptr<Weapon>> m_ptrWeapon;

		std::vector<std::shared_ptr<Site>> m_ptrSite;
		std::vector<std::shared_ptr<OwnPlatform>> m_ptrOwnPlatform;

		std::vector<std::shared_ptr<Esm>> m_ptrEsm;
		std::vector<std::shared_ptr<Ecm>> m_ptrEcm;

		std::vector<std::shared_ptr<Route>> m_ptrRoute;

		std::vector<std::shared_ptr<EsmStrategy>> m_ptrEsmStrategy;
		std::vector<std::shared_ptr<EcmStrategy>> m_ptrEcmStrategy;

		std::vector<PlatformSiteRelation> m_PlatformSiteRelation;
		std::vector<PlatformEmitterRelation> m_PlatformEmitterRelation;
		std::vector<PlatformWeaponRelation> m_PlatformWeaponRelation;
		std::vector<OwnPlatformEsmRelation> m_OwnPlatformEsmRelation;
		std::vector<EsmEsmStrategyRelation> m_EsmEsmStrategyRelation;
		std::vector<OwnPlatformEcmRelation> m_OwnPlatformEcmRelation;
		std::vector<EcmEcmStrategyRelation> m_EcmEcmStrategyRelation;
		std::vector<OwnPlatformRouteRelation> m_OwnPlatformRouteRelation;

	};

	class Vertex
	{
	public:
		
		//Vertex(void)=default;

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
		//Platform(void)=default;

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
		//Rf_values(void)=default;

		Rf_values(const unsigned int &,
			const unsigned int &,
			const unsigned int &,
			const unsigned int &,
			const unsigned int &);

		~Rf_values(void);

		//get method
		const unsigned int& getPhaseOrder(void) const;
		const unsigned int& getNumberOfPulses(void) const;
		const unsigned int& getMin(void) const;
		const unsigned int& getMax(void) const;
		const unsigned int& getSweepTime(void) const;

		//set method
		void setPhaseOrder(const unsigned int &);
		void setNumberOfPulses(const unsigned int &);
		void setMin(const unsigned int &);
		void setMax(const unsigned int &);
		void setSweepTime(const unsigned int &);

	private:
		unsigned int m_phaseOrder = 1;
		unsigned int m_numberOfPulses = 0;
		unsigned int m_min = 90;
		unsigned int m_max = 90;
		unsigned int m_sweepTime = 0;
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
		//Rf(void) = default;
		Rf(const unsigned int &,
			const unsigned int &,
			const RfType &);

		Rf(const unsigned int &,
			const unsigned int &,
			const Rf_values &, 
			const RfType &);
		Rf(const unsigned int &,
			const unsigned int &,
			const std::vector<Rf_values> &, 
			const RfType &);

		//Rf(const Rf& rf);
		//Rf& operator=(const Rf& rf);
		~Rf(void);

		//get mehtod
		const unsigned int& getRfMin(void) const;
		const unsigned int& getRfMax(void) const;
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
		void setRfMin(const unsigned int &);
		void setRfMax(const unsigned int &);
		void setRfType(const RfType &);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setAllRfValues(const std::vector<Rf_values>&);
		
	private:
		unsigned int m_min=9000;
		unsigned int m_max=10000;
		RfType m_type=RfType::BURST;
		std::vector<Rf_values> m_values;

	public:
		//const Rf_values &operator[](unsigned int valuesOrder) const;
	};

	class Pw_values
	{
	public:
		
		//Pw_values(void)=default;

		Pw_values(const unsigned int & pOrder, const unsigned int & numOfPulses, const unsigned int & min, const unsigned int & max, const unsigned int & sweepTime);
		~Pw_values(void);

		//get method
		const unsigned int& getPhaseOrder(void) const;
		const unsigned int& getNumberOfPulses(void) const;
		const unsigned int& getMin(void) const;
		const unsigned int& getMax(void) const;
		const unsigned int& getSweepTime(void) const;

		//set method
		void setPhaseOrder(const unsigned int &);
		void setNumberOfPulses(const unsigned int &);
		void setMin(const unsigned int &);
		void setMax(const unsigned int &);
		void setSweepTime(const unsigned int &);

	private:
		unsigned int m_phaseOrder=0;
		unsigned int m_numberOfPulses=0;
		unsigned int m_min=20;
		unsigned int m_max=20;
		unsigned int m_sweepTime=0;
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
		//Pw(void)=default;
		Pw(const unsigned int &, 
			const unsigned int &, 
			const PwType &);

		Pw(const unsigned int &,
			const unsigned int &,
			const Pw_values &,
			const PwType &);
		Pw(const unsigned int &,
			const unsigned int &,
			const std::vector<Pw_values > &,
			const PwType &);
		~Pw(void);

		//get mehtod
		const unsigned int& getPwMin(void) const;
		const unsigned int& getPwMax(void) const;
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
		void setPwMin(const unsigned int &);
		void setPwMax(const unsigned int &);
		void setPwType(const PwType &);

		//赋值覆盖，可用此成员函数覆盖住默认构造函数初始化的对象
		void setAllPwValues(const std::vector<Pw_values>&);

	private:
		unsigned int m_min=20;
		unsigned int m_max=20;
		PwType m_type=PwType::FIX;
		std::vector<Pw_values> m_values;

	public:
		//const Pw_values &operator[](unsigned int valuesOrder) const;
	};

	class Pri_values
	{
	public:
		//Pri_values(void) = default;
		
		Pri_values(const unsigned int &,
			const unsigned int &,
			const unsigned int &,
			const unsigned int &,
			const unsigned int &);

		~Pri_values(void);

		//get method
		const unsigned int& getPhaseOrder(void) const;
		const unsigned int& getNumberOfPulses(void) const;
		const unsigned int& getMin(void) const;
		const unsigned int& getMax(void) const;
		const unsigned int& getSweepTime(void) const;

		//set method
		void setPhaseOrder(const unsigned int &);
		void setNumberOfPulses(const unsigned int &);
		void setMin(const unsigned int &);
		void setMax(const unsigned int &);
		void setSweepTime(const unsigned int &);

	private:
		unsigned int m_phaseOrder=1;
		unsigned int m_numberOfPulses=0;
		unsigned int m_min=90;
		unsigned int m_max=90;
		unsigned int m_sweepTime=0;
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
		//Pri(void) = default;
		Pri(const unsigned int &,
			const unsigned int &,
			const PriType &);

		Pri(const unsigned int &,
			const unsigned int &,
			const Pri_values &,
			const PriType &);

		Pri(const unsigned int &,
			const unsigned int &,
			const std::vector<Pri_values> &,
			const PriType &);

		~Pri(void);


		//get mehtod
		const unsigned int& getPriMin(void) const;
		const unsigned int& getPriMax(void) const;
		const PriType& getPriType(void) const;

		//获取容纳Pri_values的容器对象
		std::vector<Pri_values>& getAllPriValues(void);

		//判断Pri_values值不为空
		bool isValuesEmpty();

		//根据Pri_value的顺序获取不同Pri_values的对象。
		//在获取Pri_value前应判断容器是否为空
		Pri_values& getPriValue(unsigned int valueOrder);
		
		//set method
		void setPriMin(const unsigned int &);
		void setPriMax(const unsigned int &);
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
		unsigned int m_min=90;
		unsigned int m_max=100;
		PriType m_type = PriType::FIX;
		std::vector<Pri_values> m_values;

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
		
		//Scan(void) = default;
		Scan(const unsigned int &,
			const unsigned int &,
			const ScanType &);
		~Scan(void);

		//get mehtod
		const unsigned int& getScanMin(void) const;
		const unsigned int& getScanMax(void) const;
		const ScanType& getScanType(void) const;
		
		//set method
		void setScanMin(const unsigned int &);
		void setScanMax(const unsigned int &);
		void setScanType(const ScanType &);
		
	private:
		unsigned int m_min=2;
		unsigned int m_max=2;
		ScanType m_type = ScanType::SECTORIAL;
	};

	class Erp
	{
	public:
		
		//Erp(void) = default;
		Erp(const unsigned int &,
			const unsigned int &);
		~Erp(void);

		//get mehtod
		const unsigned int& getErpMin(void) const;
		const unsigned int& getErpMax(void) const;
		
		//set method
		void setErpMin(const unsigned int &);
		void setErpMax(const unsigned int &);
		

	private:
		unsigned int m_min=50000;
		unsigned int m_max=50000;
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
		//Radar_Mode(void);

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
		Rf m_rf;
		Pw m_pw;
		Pri m_pri;
		Scan m_scan;
		Erp m_erp;
	};

	class Emitter
	{
	public:
		//请注意，数据成员中自定义类虽然都有默认构造函数，但本质上没有完全实例化类对象，
		//由于充满不确定性，调用默认构造可能会引起一些未知错误；
		//此构造函数用于编译器隐含调用，使用者请不要使用默认构造函数
		//Emitter(void);
		Emitter(const std::string &, std::shared_ptr<Radar_Mode> &);
		Emitter(const std::string &, std::vector<std::shared_ptr<Radar_Mode>> &);
		~Emitter(void);

		//get method
		const std::string& getName(void) const ;

		//获取RadarMode容器对象
		std::vector<std::shared_ptr<Radar_Mode>>& getAllPtr2RadarModes(void);

		bool isRadarModeEmpty(void);

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
		std::vector<std::shared_ptr<Radar_Mode>> m_ptrRadarMode;
	};

	class Weapon
	{
	public:
		//不用使用标准容器类直接装带有string类型成员数据的类对象，而应该是该对象的指针
		//Weapon(void);
		Weapon(const std::string&,const unsigned int&, const unsigned int&);
		~Weapon(void);

		const std::string& getName(void) const;
		const unsigned int& getCEPR(void) const;
		const unsigned int& getWeaponAreaCoverage(void) const;

		void setName(const std::string&);
		void setCEPR(const unsigned int&);
		void setWeaponAreaCoverage(const unsigned int&);


	private:
		std::string m_name{"Weapon 1"};
		unsigned int m_cepr{50000};
		unsigned int m_weaponAreaCoverage{100000};
	};

	class Site
	{
	public:
		//不用使用标准容器类直接装带有string类型成员数据的类对象，而应该是该对象的指针
		//Site(void);
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
		Point(const double&, const double&, const double&);
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
		//Mission(void);

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
		Point m_startPoint;
		Point m_endPoint;
		std::vector<Point> m_targetPoints;
	};
		
	enum class OwnPlatformType
	{
		AIR=0
		
	};

	class OwnPlatform
	{
	public:
		//OwnPlatform(void);
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
		Mission m_mission;
	};

	class Esm
	{
	public:
		//Esm(void);
		Esm(const std::string&, const double&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&);
		~Esm(void);

		const std::string& getName(void);
		const double& getDwellFreqResolution(void);
		const unsigned int& getTuningStep(void);
		const unsigned int& getRfCovMin(void);
		const unsigned int& getRfCovMax(void);
		const unsigned int& getNumPulsesAcquisition(void);
		const unsigned int& getNumPulsesAlarm(void);

		void setName(const std::string&);
		void setDwellFreqResolution(const double&);
		void setTuningStep(const int&);
		void setRfCovMin(const int&);
		void setRfCovMax(const int&);
		void setNumPulsesAcquisition(const int&);
		void setNumPulsesAlarm(const int&);
		
	private:
		std::string m_name{ "Esm1" };
		double m_dwellFreqResolution{100.0};
		unsigned int m_tuningStep{ 20 };
		unsigned int m_rfCovMin{ 500 };
		unsigned int m_rfCovMax{ 12000 };
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
		//Ecm(void);

		Ecm(const std::string&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&, const Tech&);

		Ecm(const std::string&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&, const std::vector<Tech>&);
		~Ecm(void);

		const std::string& getName(void);
		const unsigned int& getPt(void);
		const unsigned int& getGain(void);
		const unsigned int& getRfMin(void);
		const unsigned int& getRfMax(void);

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
		void setPt(const unsigned int&);
		void setGain(const unsigned int&);
		void setRfMin(const unsigned int&);
		void setRfMax(const unsigned int&);

		//以容器为单位，整体赋值修改
		void setAllTechs(const std::vector<Tech>&);

	private:
		std::string m_name{ "Ecm1" };
		unsigned int m_pt{ 20000 };
		unsigned int m_gain{ 10 };
		unsigned int m_rfMin{ 9000 };
		unsigned int m_rfMax{ 9500 };
		std::vector<Tech> m_techName{Tech::NOISE};
	};

	class WayPoint
	{
	public:
		//WayPoint(void);
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
		//Route(void);
		Route(const std::string&, const WayPoint&);
		Route(const std::string&, const std::vector<WayPoint>&);
		~Route(void);

		//get name
		const std::string& getName(void);

		bool isWayPointEmpty(void);

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
		std::vector<WayPoint> m_wayPoints;
	};

	class Location
	{
	public:
		//Location(void);
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
		//DwellSquence(void);
		DwellSquence(const unsigned int&, const unsigned int&, const unsigned int&, const double&, const double&);
		~DwellSquence(void);

		//get method;
		const unsigned int& getIndex(void);
		const unsigned int& getMinFreq(void);
		const unsigned int& getMaxFreq(void);
		const double& getStartTime(void);
		const double& getEndTime(void);

		//set method;
		void setIndex(const unsigned int&);
		void setMinFreq(const unsigned int&);
		void setMaxFreq(const unsigned int&);
		void setStartTime(const double&);
		void setEndTime(const double&);

	private:
		unsigned int m_index{ 1 };
		unsigned int m_minFreq{ 100 };
		unsigned int m_maxFreq{ 200 };
		double m_startTime{ 0.0 };
		double m_endTime{ 30.0 };
	};

	class EsmStrategySection
	{
	public:
		//EsmStrategySection(void);
		EsmStrategySection(const double&, const double&, const Location&, const Location&, const DwellSquence&);
		EsmStrategySection(const double&, const double&, const Location&, const Location&, const std::vector<DwellSquence>&);
		~EsmStrategySection(void);

		//get method
		const double& getStartTime(void);
		const double& getEndTime(void);
		Location& getStartLocation(void);
		Location& getEndLocation(void);

		bool isDwellSquenceEmpty(void);

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
		Location m_startLocation;
		Location m_endLocation;
		std::vector<DwellSquence> m_dwellSquences;
	};

	class EsmStrategy
	{
	public:
		//EsmStrategy(void);
		EsmStrategy(const std::string&, const std::shared_ptr<EsmStrategySection>&);
		EsmStrategy(const std::string&, const std::vector<std::shared_ptr<EsmStrategySection>>&);
		~EsmStrategy(void);

		//get method
		const std::string& getName(void) const;

		//获取EsmStrategySection指针容器对象
		std::vector<std::shared_ptr<EsmStrategySection>>& getAllPtr2Sections(void);

		bool isSectionEmpty(void);

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
		std::vector<std::shared_ptr<EsmStrategySection>> m_ptrSections;

	};

	
	class EcmStrategySection
	{
	public:
		//EcmStrategySection(void);
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
		Location m_startLocation;
		Location m_endLocation;
		Tech m_tech{ Tech::NOISE };
	};

	class EcmStrategy
	{
	public:
		//EcmStrategy(void);
		EcmStrategy(const std::string&, const std::shared_ptr<EcmStrategySection>&);
		EcmStrategy(const std::string&, const std::vector<std::shared_ptr<EcmStrategySection>>&);
		~EcmStrategy(void);

		//get method
		const std::string& getName(void) const;

		//获取EcmStrategySection指针容器对象
		std::vector<std::shared_ptr<EcmStrategySection>>& getAllPtr2Sections(void);

		//判断EcmStrategySection指针容器对象是否为空
		bool isSectionEmpty(void);

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
		std::vector<std::shared_ptr<EcmStrategySection>> m_ptrSections;
	};

	class PlatformSiteRelation
	{
	public:
		//PlatformSiteRelation(void);
		PlatformSiteRelation(const std::shared_ptr<Platform>,const std::shared_ptr<Site>);
		~PlatformSiteRelation(void);

		//get name;
		const std::string& getPlatformName(void);
		const std::string& getSiteName(void);

		//set/moditify pointer of Object
		void setPlatform(const std::shared_ptr<Platform>);
		void setSite(const std::shared_ptr<Site>);
		

	private:
		std::shared_ptr<Platform> m_ptrPlatform;
		std::shared_ptr<Site> m_ptrSite;
	};

	class PlatformEmitterRelation
	{
	public:
		//PlatformEmitterRelation(void);
		PlatformEmitterRelation(const std::shared_ptr<Platform>, const std::shared_ptr<Emitter>);
		~PlatformEmitterRelation(void);

		//get name;
		const std::string& getPlatformName(void);
		const std::string& getEmitterName(void);

		//set/moditify pointer of Object
		void setPlatform(const std::shared_ptr<Platform>);
		void setEmitter(const std::shared_ptr<Emitter>);

	private:
		std::shared_ptr<Platform> m_ptrPlatform;
		std::shared_ptr<Emitter> m_ptrEmitter;
	};

	class PlatformWeaponRelation
	{
	public:
		//PlatformWeaponRelation(void);
		PlatformWeaponRelation(const std::shared_ptr<Platform>, const std::shared_ptr<Weapon>);
		~PlatformWeaponRelation(void);

		//get name;
		const std::string& getPlatformName(void);
		const std::string& getWeaponName(void);

		//set/moditify pointer of Object
		void setPlatform(const std::shared_ptr<Platform>);
		void setWeapon(const std::shared_ptr<Weapon>);

	private:
		std::shared_ptr<Platform> m_ptrPlatform;
		std::shared_ptr<Weapon> m_ptrWeapon;
	};

	class OwnPlatformEsmRelation
	{
	public:
		//OwnPlatformEsmRelation(void);
		OwnPlatformEsmRelation(const std::shared_ptr<OwnPlatform>, const std::shared_ptr<Esm>);
		~OwnPlatformEsmRelation(void);

		//get name;
		const std::string& getOwnPlatformName(void);
		const std::string& getEsmName(void);

		//set/moditify pointer of Object
		void setOwnPlatform(const std::shared_ptr<OwnPlatform>);
		void setEsm(const std::shared_ptr<Esm>);

	private:
		std::shared_ptr<OwnPlatform> m_ptrOwnPlatform;
		std::shared_ptr<Esm> m_ptrEsm;
	};

	class EsmEsmStrategyRelation
	{
	public:
		//EsmEsmStrategyRelation(void);
		EsmEsmStrategyRelation(const std::shared_ptr<Esm>, const std::shared_ptr<EsmStrategy>);
		~EsmEsmStrategyRelation(void);

		//get name;
		const std::string& getEsmName(void);
		const std::string& getEsmStrategyName(void);

		//set/moditify pointer of Object
		void setEsm(const std::shared_ptr<Esm>);
		void setEsmStrategy(const std::shared_ptr<EsmStrategy>);

	private:
		std::shared_ptr<Esm> m_ptrEsm;
		std::shared_ptr<EsmStrategy> m_ptrEsmStrategy;
	};

	class OwnPlatformEcmRelation
	{
	public:
		//OwnPlatformEcmRelation(void);
		OwnPlatformEcmRelation(const std::shared_ptr<OwnPlatform>, const std::shared_ptr<Ecm>);
		~OwnPlatformEcmRelation(void);

		//get name;
		const std::string& getOwnPlatformName(void);
		const std::string& getEcmName(void);

		//set/moditify pointer of Object
		void setOwnPlatform(const std::shared_ptr<OwnPlatform>);
		void setEcm(const std::shared_ptr<Ecm>);

	private:
		std::shared_ptr<OwnPlatform> m_ptrOwnPlatform;
		std::shared_ptr<Ecm> m_ptrEcm;
	};

	class EcmEcmStrategyRelation
	{
	public:
		//EcmEcmStrategyRelation(void);
		EcmEcmStrategyRelation(const std::shared_ptr<Ecm>, const std::shared_ptr<EcmStrategy>);
		~EcmEcmStrategyRelation(void);

		//get name;
		const std::string& getEcmName(void);
		const std::string& getEcmStrategyName(void);

		//set/moditify pointer of Object
		void setEcm(const std::shared_ptr<Ecm>);
		void setEcmStrategy(const std::shared_ptr<EcmStrategy>);

	private:
		std::shared_ptr<Ecm> m_ptrEcm;
		std::shared_ptr<EcmStrategy> m_ptrEcmStrategy;
	};

	class OwnPlatformRouteRelation
	{
	public:
		//OwnPlatformRouteRelation(void);
		OwnPlatformRouteRelation(const std::shared_ptr<OwnPlatform>, const std::shared_ptr<Route>);
		~OwnPlatformRouteRelation(void);

		//get name;
		const std::string& getOwnPlatformName(void);
		const std::string& getRouteName(void);

		//set/moditify pointer of Object
		void setOwnPlatform(const std::shared_ptr<OwnPlatform>);
		void setRoute(const std::shared_ptr<Route>);

	private:
		std::shared_ptr<OwnPlatform> m_ptrOwnPlatform;
		std::shared_ptr<Route> m_ptrRoute;
	};

}

#endif // !__SCENARIO__