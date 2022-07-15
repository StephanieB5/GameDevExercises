#include "ParticleSystem.h"
#include <math.h>
#include <random>
#include <functional>

namespace
{
	int constexpr numParticlePerSystem = 60000000;
	int constexpr numEmissiveParticle = 5000;
	float constexpr fullColour = 1.f;
	float constexpr noColour = 0.f;
	float constexpr particleSize = 0.5f;
}

// EXCERCISE: Profile both the optimized and the non-optimized version of the DataProcessor::Process method
// You can switch between the two by uncommenting line 5 in ParticleSystem.h

#ifdef UseOptimizedVersion
void Particle::InitializeToASpark(const bool isEmissive, const float locationX, const float locationY, const float locationZ)
{
    m_x = locationX;
    m_y = locationY;
    m_z = locationZ;

    m_points.resize(Particle::numPointsPerQuad);
    for (int i = 0; i < Particle::numPointsPerQuad; ++i)
    {
        Point point = m_points[i];
        point.m_red = fullColour;
        point.m_green = noColour;
        point.m_blue = noColour;
        point.m_alpha = noColour;

        point.m_x = locationX;
        point.m_y = locationY;
        point.m_z = locationZ;
    }
    m_points[1].m_x += particleSize;
    m_points[2].m_x += particleSize;

    m_points[2].m_y += particleSize;
    m_points[3].m_y += particleSize;

    if (isEmissive)
    {
        m_isEmmissive = true;
        for (int i = 0; i < Particle::numPointsPerQuad; ++i)
        {
            Point point = m_points[i];
            point.m_emissiveRed = fullColour;
            point.m_emissiveGreen = noColour;
            point.m_emissiveBlue = noColour;
            point.m_usePointNormals = i == 0;
        }
    }
}
#else
//
//-----------------------------------------------DON'T CHANGE CODE PAST THIS POINT -----------------------------------------//
//

void Particle::InitializeToASpark(const bool isEmissive, const float locationX, const float locationY, const float locationZ)
{
	m_x = locationX;
	m_y = locationY;
	m_z = locationZ;

	m_points.resize(Particle::numPointsPerQuad);
	for (int i = 0; i < Particle::numPointsPerQuad; ++i)
	{
		Point point = m_points[i];
		point.m_red = fullColour;
		point.m_green = noColour;
		point.m_blue = noColour;
		point.m_alpha = noColour;

        point.m_x = locationX;
        point.m_y = locationY;
        point.m_z = locationZ;
	}
	m_points[1].m_x += particleSize;
	m_points[2].m_x += particleSize;

	m_points[2].m_y += particleSize;
	m_points[3].m_y += particleSize;

	if (isEmissive)
	{
		m_isEmmissive = true;
		for (int i = 0; i < Particle::numPointsPerQuad; ++i)
		{
			Point point = m_points[i];
			point.m_emissiveRed = fullColour;
			point.m_emissiveGreen = noColour;
			point.m_emissiveBlue = noColour;
            point.m_usePointNormals = i == 0;  
		}
	}
}
#endif

void ParticleSystem::SendSparks(const float originX, const float originY, const float originZ)
{
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution(0, static_cast<float>(numParticlePerSystem));
	auto locationOffset = std::bind(distribution, generator);

	for (int i = 0; i < numEmissiveParticle; ++i)
	{
		m_particles[i].InitializeToASpark(true,
			originX + locationOffset(),
			originY + locationOffset(),
			originZ + locationOffset());
	}

	for (int i = numEmissiveParticle; i < numParticlePerSystem; ++i)
	{
		m_particles[i].InitializeToASpark(false,
			originX + locationOffset(),
			originY + locationOffset(),
			originZ + locationOffset());
	}
}

ParticleSystem::ParticleSystem()
{
	m_particles.resize(numParticlePerSystem);
}


