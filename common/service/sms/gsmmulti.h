/* (c) 2002-2006 by Marcin Wiacek */

#ifndef __gsm_multi_h
#define __gsm_multi_h

#if defined(_MSC_VER) && defined(__cplusplus)
    extern "C" {
#endif

#include "../../gsmcomon.h"
#include "../gsmlogo.h"
#include "../gsmcal.h"
#include "../gsmpbk.h"
#include "../gsmdata.h"
#include "../gsmring.h"
#include "gsmsms.h"

/* ---------------------- multi SMS --------------------------------------- */

/* Identifiers for Smart Messaging 3.0 multipart SMS */

#define SM30_ISOTEXT      0 /* ISO 8859-1 text */
#define SM30_UNICODETEXT  1
#define SM30_OTA	  2
#define SM30_RINGTONE     3
#define SM30_PROFILENAME  4
/* ... */
#define SM30_SCREENSAVER  6

/* Identifiers for Alcatel Terminal Data Download */
#define ALCATELTDD_PICTURE     4
#define ALCATELTDD_ANIMATION   5
#define ALCATELTDD_SMSTEMPLATE 6

void GSM_SMSCounter(int		 	MessageLength,
		    unsigned char       *MessageBuffer,
		    GSM_UDH	     	UDHType,
		    GSM_Coding_Type     Coding,
		    int		 	*SMSNum,
		    int		 	*CharsLeft);

GSM_Error GSM_AddSMS_Text_UDH(GSM_MultiSMSMessage       *SMS,
				GSM_Coding_Type	 	Coding,
				char		    	*Buffer,
				int		     	BufferLen,
				bool		    	UDH,
				int		     	*UsedText,
				int		     	*CopiedText,
				int		     	*CopiedSMSText);

void GSM_MakeMultiPartSMS(GSM_MultiSMSMessage   *SMS,
			  unsigned char	 	*MessageBuffer,
			  int		   	MessageLength,
			  GSM_UDH	       	UDHType,
			  GSM_Coding_Type       Coding,
			  int		   	Class,
			  unsigned char	 	RejectDuplicates);

void GSM_Find_Free_Used_SMS2(GSM_Coding_Type Coding,GSM_SMSMessage SMS, int *UsedText, int *FreeText, int *FreeBytes);

unsigned char GSM_MakeSMSIDFromTime(void);


#if defined(_MSC_VER) && defined(__cplusplus)
    }
#endif

#endif

/* How should editor hadle tabs in this file? Add editor commands here.
 * vim: noexpandtab sw=8 ts=8 sts=8:
 */
