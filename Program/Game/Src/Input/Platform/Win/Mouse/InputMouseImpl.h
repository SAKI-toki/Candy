/*****************************************************************//**
 * \file   InputMouseImpl.h
 * \brief  �}�E�X���͂̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_INPUT_MOUSE_IMPL_H
#define CANDY_INPUT_MOUSE_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace Input::Impl
{
	class MouseImpl
	{
	protected:
		// PC��ʏ�̈ʒu�擾
		Vec4 getScreenPos()const;
		// PC��ʏ�̈ʒu����A�v����ʏ�̈ʒu�ɕϊ�
		Vec4 toClientPos(const Vec4 _screenPos)const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_MOUSE_IMPL_H
