/*****************************************************************//**
 * \file   ReadDDS.h
 * \brief  DDSÇÃì«Ç›çûÇ›
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_TEXTURE_READ_DDS_H
#define CANDY_TEXTURE_READ_DDS_H

CANDY_NAMESPACE_BEGIN

namespace Texture::DDS
{
	// ÉÅÉÇÉäämï€ÇµÇ¬Ç¬ì«Ç›çûÇ›
	std::byte* ReadAlloc(const std::byte* const _bytes, const u64 _byteSize);
}

CANDY_NAMESPACE_END

#endif // CANDY_TEXTURE_READ_DDS_H
