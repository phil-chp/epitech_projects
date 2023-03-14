/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** ISound
*/

#ifndef ISOUND_HPP_
    #define ISOUND_HPP_

namespace rl {
    class ISound {
        public:
            virtual void play()      const = 0;
            virtual void unload()          = 0;
            virtual void update(void const *data, int frameCount) const = 0;
            virtual void pause()     const = 0;
            virtual void resume()    const = 0;
            virtual void stop()      const = 0;
            virtual bool isPlaying() const = 0;
    };

    // Concept of volume
    class ASound : public ISound {
        public:
            ASound(float volume = 0.5f) : _volume(volume) {};
            ~ASound() = default;

            virtual void updateVolume() const = 0;

            void setVolume(float volume) {
                this->_volume = volume;
                this->updateVolume();
            }

            float getVolume() const {
                return (this->_volume);
            }

        private:
            float _volume;
    };

}

#endif /* !ISOUND_HPP_ */
