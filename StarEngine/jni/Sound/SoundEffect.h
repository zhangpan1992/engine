#pragma once

#include "BaseSound.h"

namespace star
{
	const int MAX_SAMPLES = 10;

	class SoundEffect final : public BaseSound
	{
	public:
		SoundEffect(const tstring& path, uint8 channel = 0);
		~SoundEffect();

		virtual void Play(int loopTime = 0);
		virtual void Stop();
		virtual void Pause();
		virtual void Resume();

		virtual void SetChannel(uint8 channel);
		virtual void UnsetChannel();

	#ifdef ANDROID
		void SetVolume(float volume);
	#endif
		float GetVolume() const;

		void SetMuted(bool muted);
		bool IsMuted() const;

	private:
#ifdef DESKTOP
		void SetSoundVolume(int volume);

		static int PLAY_CHANNELS;
		int mPlayChannel;
		Mix_Chunk * mpSound;
#else
		void RegisterCallback(SLPlayItf & player);

		static void MusicStoppedCallback(
			SLPlayItf caller,
			void *pContext,
			SLuint32 event
			);

		std::vector<SLObjectItf> mPlayerObjs;
		std::vector<SLPlayItf> mPlayers;
#endif	

		SoundEffect(const SoundEffect& yRef);
		SoundEffect(SoundEffect&& yRef);
		SoundEffect& operator=(const SoundEffect& yRef);
		SoundEffect& operator=(SoundEffect&& yRef);
	};
}
