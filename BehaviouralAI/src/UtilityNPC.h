#pragma once
#include "World.h"
#include "BaseNPC.h"
#include "UtilityValue.h"
#include "UtilityScore.h"
#include <map>

using namespace UtilitySystem;

enum class Resource{Food, Water, Rest, Logs, BuildHouse};

class UtilityNPC : public BaseNPC
{
public:
	UtilityNPC(World* pWorld) : BaseNPC(pWorld)
	{
		m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_waterValue.setMinMaxValues(0, 20);
		m_waterValue.setValue(getWaterValue());

		m_foodValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_foodValue.setMinMaxValues(5, 25);
		m_foodValue.setValue(getFoodValue());

		m_restValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_restValue.setMinMaxValues(1, 20);
		m_restValue.setValue(getRestValue());

		m_logValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_logValue.setMinMaxValues(0, 1);
		m_logValue.setValue(getNumberOfLogs());

		UtilityScore* pWaterScore = new UtilityScore();
		pWaterScore->addUtilityValue(&m_waterValue, 1.0f);
		m_pUtilityScoreMap[Resource::Water] = pWaterScore;

		UtilityScore* pFoodScore = new UtilityScore();
		pFoodScore->addUtilityValue(&m_foodValue, 1.0f);
		m_pUtilityScoreMap[Resource::Food] = pFoodScore;

		UtilityScore* pRestScore = new UtilityScore();
		pRestScore->addUtilityValue(&m_restValue, 1.0f);
		m_pUtilityScoreMap[Resource::Rest] = pRestScore;

		UtilityScore* pLogScore = new UtilityScore();
		pLogScore->addUtilityValue(&m_logValue, 1.0f);
		m_pUtilityScoreMap[Resource::Logs] = pLogScore;
	}

	~UtilityNPC();

protected:
	void selectAction(float a_fdeltaTime) override;

private:
	UtilityValue m_waterValue;
	UtilityValue m_foodValue;
	UtilityValue m_restValue;
	UtilityValue m_logValue;
	UtilityValue m_BuildValue;

	std::map<Resource, UtilityScore*> m_pUtilityScoreMap;

};

