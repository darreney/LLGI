
#pragma once

#include "../LLGI.Texture.h"
#include "LLGI.GraphicsMetal.h"

namespace LLGI
{

struct Texture_Impl;

class TextureMetal : public Texture
{
private:
	ReferenceObject* owner_ = nullptr;
	Texture_Impl* impl = nullptr;
	std::vector<uint8_t> data;

public:
	TextureMetal();
	virtual ~TextureMetal();

	bool Initialize(GraphicsMetal* owner, const TextureInitializationParameter& parameter);
	bool Initialize(GraphicsMetal* owner, const RenderTextureInitializationParameter& parameter);
	bool Initialize(GraphicsMetal* owner, const DepthTextureInitializationParameter& parameter);

	void Reset(id<MTLTexture> nativeTexture);
	void* Lock() override;
	void Unlock() override;
	Vec2I GetSizeAs2D() const override;

	Texture_Impl* GetImpl() const;
};

} // namespace LLGI
