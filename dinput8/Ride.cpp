#include "Ride.h"

using RideA = EntityINS::EntityModule::Ride;

RideA::Ride()
{

}

RideA::Ride(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Ride_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xE8 });
}

RideA::~Ride()
{
	Ride_PTR = NULL;
}