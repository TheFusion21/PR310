#pragma once

// EXTERNAL INCLUDES
#include <chrono>
// INTERNAL INCLUDES
#include "types.h"

namespace Engine::Utils
{
	enum class TimeType {
		miliseconds = 1,
		seconds = 1000,
		minutes = 60000,
		hours = 3600000
	};
	/*! @class Timer \file time.h
	 *  @brief a timer to measure a time span with
	 *  @author Kay Hennig
	 *  @date 10.08.2020
	 */
	class Timer
	{
	private:
		bool m_Started;
		std::chrono::time_point<std::chrono::system_clock> StartTimePoint;

	public:
		Timer()
			: m_Started(false) {}

		/*! @brief Starts the timer */
		void Start();
		/*! @brief Stops and resets timer */
		void Stop();
		/*! @brief get the duration of the timer
		 *  @param t type to convert to
		 *  @return duration in type
		 */
		real GetDuration(TimeType t);
		/*! @brief check if the timer is started
		 *  @return timer is running
		 */
		inline bool IsStarted() const { return m_Started; }
	};
	/*! @class Time \file time.h
	 *  @brief time to make stuff frame independent
	 *  @author Kay Hennig
	 *  @date 10.08.2020
	 */
	class Time
	{
	private:
		Time() {}
		static real _deltaTime;
		static real _time;
		static real _sinTime;
		static Timer deltaTimer;
	public:
		/*! @brief deltaTime for counter or animation or shit (Read Only) */
		static const real& deltaTime;
		/*! @brief time since program start (Read Only) */
		static const real& time;
		/*! @brief the sin value of time (Read Only) */
		static const real& sinTime;
		/*! @brief Start time measurement */
		static void Start();
		/*! @brief updates the time values and the internal timer should be called once per frame*/
		static void Update();

	};
}