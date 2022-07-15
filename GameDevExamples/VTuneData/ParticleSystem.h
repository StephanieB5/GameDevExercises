#pragma once
#include <vector>
#include <string>

// #define UseOptimizedVersion

#ifdef UseOptimizedVersion
#include <array>

struct Point
{
    float m_red = 0.f;
    bool m_usePointNormals = false;
    float m_emissiveRed = 0.f;
    std::string m_debugLogString;
    float m_x = 0.f;
    float m_normalX = 1.f;
    float m_green = 0.f;
    float m_emissiveGreen = 0.f;
    float m_y = 0.f;
    float m_normalY = 0.f;
    float m_blue = 0.f;
    float m_emissiveBlue = 0.f;
    float m_z = 0.f;
    float m_normalZ = 0.f;
    float m_alpha = 0.f;
    float m_emissiveAlpha = 0.f;
};

class Particle
{
public:
    static int constexpr numPointsPerQuad = 4;

    void InitializeToASpark(const bool isEmissive, const float locationX, const float locationY, const float locationZ);

    std::vector<Point> m_points;
    bool m_isEmmissive = false;
    float m_x = 0.f;
    float m_y = 0.f;
    float m_z = 0.f;
};

class ParticleSystem
{
public:
    ParticleSystem();

    void SendSparks(float originX, float originY, float originZ);

    std::vector<Particle> m_particles;
};

#else
//
//-----------------------------------------------DON'T CHANGE CODE PAST THIS POINT -----------------------------------------//
//

struct Point
{
	float m_red = 0.f;
	bool m_usePointNormals = false;
	float m_emissiveRed = 0.f;
	std::string m_debugLogString;
	float m_x = 0.f;
	float m_normalX = 1.f;
	float m_green = 0.f;
	float m_emissiveGreen = 0.f;
	float m_y = 0.f;
	float m_normalY = 0.f;
	float m_blue = 0.f;
	float m_emissiveBlue = 0.f;
	float m_z = 0.f;
	float m_normalZ = 0.f;
	float m_alpha = 0.f;
	float m_emissiveAlpha = 0.f;
};

class Particle
{
public:
    static int constexpr numPointsPerQuad = 4;

	void InitializeToASpark(const bool isEmissive, const float locationX, const float locationY, const float locationZ);

	std::vector<Point> m_points;
	bool m_isEmmissive = false;
	float m_x = 0.f;
	float m_y = 0.f;
	float m_z = 0.f;
};

class ParticleSystem
{
public:
	ParticleSystem();

	void SendSparks(float originX, float originY, float originZ);

	std::vector<Particle> m_particles;
};
#endif


