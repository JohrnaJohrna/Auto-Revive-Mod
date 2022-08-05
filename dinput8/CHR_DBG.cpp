#include "CHR_DBG.h"

Signature CHRDBG = {
	"\x48\x8B\x05\x00\x00\x00\x00\x41\x83\xFF\x02\x00\x00\x48\x85\xC0",
	"xxx????xxxx??xxx",
	false
};

Signature CHRDBG_FLAGS = {
	"\x80\x3D\x00\x00\x00\x00\x00\x0F\x85\x00\x00\x00\x00\x32\xC0\x48",
	"xx????xxx????xxx",
	false
};

CHR_DBG::CHR_DBG()
{
	Memory_S mem;

	uintptr_t SigAddr = mem.GetSignature_BaseAddr(CHRDBG, { 0x3, 0x7 });
	CHR_DBG_BASE = *(uintptr_t*)SigAddr;
	SigAddr = mem.GetSignature_BaseAddr(CHRDBG_FLAGS, { 0x2, 0x7 });
	CHR_DBG_FLAGS = SigAddr;
}
CHR_DBG::CHR_DBG(const CHR_DBG& chr_dbg)
{

}
CHR_DBG::~CHR_DBG()
{
	CHR_DBG::CHR_DBG_BASE = NULL;
}
CHR_DBG& CHR_DBG::operator=(const CHR_DBG& chr_dbg)
{
	return *this;
}

//CHR_DBG DAT_GET
float* CHR_DBG::GetHitStopVal()
{
	Memory_S Memory_S;
	float* HitStopVal = (float*)Memory_S.GetPointerAddress(CHR_DBG_BASE, { 0x98 });
	return HitStopVal;
}