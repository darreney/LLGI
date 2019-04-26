
#pragma once

#include "../LLGI.Texture.h"
#include "LLGI.GraphicsMetal.h"

namespace LLGI
{

struct Texture_Impl;

class TextureMetal : public Texture
{
private:
	GraphicsMetal* graphics_ = nullptr;
	Texture_Impl* impl = nullptr;
	std::vector<uint8_t> data;

public:
	TextureMetal();
	virtual ~TextureMetal();

	bool Initialize(Graphics* graphics, Vec2I size);
	void* Lock() override;
	void Unlock() override;
	Vec2I GetSizeAs2D() override;
	bool IsRenderTexture() const override;
	bool IsDepthTexture() const override;

	Texture_Impl* GetImpl();
};

} // namespace LLGI
