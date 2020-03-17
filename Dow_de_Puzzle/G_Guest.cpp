#include "G_Guest.h"



G_Guest::G_Guest(const std::vector<double>& info)
{
	Initialize(info);
}


G_Guest::~G_Guest()
{
}

void G_Guest::Initialize(const std::vector<double>& info)
{
}

void G_Guest::Update(std::vector<Enemy*>& enemys, std::vector<Friend*>& friends, std::vector<Gimic*>& gimics, const Vector2 & screen, int & score)
{
}

void G_Guest::Finalize()
{
}
