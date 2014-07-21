//!
//! @file 				RingBuff-Buffer.hpp
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created 			2013-07-30
//! @last-modified	2014-07-21
//! @brief 				Implements the ring buffer.
//! @details
//!						See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

// System libraries
#include <stdint.h>

// User source
#include "RingBuff-Config.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace RingBuff
{
	//===============================================================================================//
	//============================================= CLASS ===========================================//
	//===============================================================================================//
	class Buffer
	{	
		
		public:
		
			
			
			//===============================================================================================//
			//==================================== CONSTRUCTORS/DESTRUCTOR ==================================//
			//===============================================================================================//
			
			//! @brief		Initialises the buffer, ready for use.
			Buffer(char* bufPtr, uint32_t size);
			
			//===============================================================================================//
			//=================================== PUBLIC METHOD DECLARATIONS ================================//
			//===============================================================================================//
			
			//! @brief		Reads up to a number of bytes from the FIFO buffer.
			//! @details	Will read numBytes of data, unless there is not enough data to read, in which case
			//!				returns early.
			//! @returns	Number of bytes read (which could be from 0 to numBytes).
			uint32_t Read(char* buff, uint32_t numBytes);
			
			//! @brief		Writes a number of bytes to the FIFO buffer.
			//! @details	Will return early if there is no more space left in the buffer. Does
			//!				not write over contents.
			uint32_t Write(const char* buff, uint32_t numBytes);
			
			//===============================================================================================//
			//======================================= PUBLIC VARIABLES ======================================//
			//===============================================================================================//
			
			
			
		private:
		
			//! @brief		Pointer to buffer. Set by Buffer().
			char* fifoBuff;
			
			//! @brief		The size of the buffer (in bytes). Set by Buffer().
			uint32_t size;
			
			//! @brief		The head position, measured in bytes from the start of the buffer (bufPtr).
			uint32_t headPos;
			
			//! @brief		The tail position, measured in bytes from the start of the buffer (bufPtr).
			uint32_t tailPos;
		
	};

	//===============================================================================================//
	//================================= PUBLIC TEMPLATE METHOD DEFINITIONS ==========================//
	//===============================================================================================//
	
	// none
	
} // namespace RingBuff

#endif // #ifndef #ifndef RING_BUFFER_H

// EOF