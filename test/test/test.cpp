#include "stdafx.h"
#include "base64.h"
#include <fstream>      // std::ofstream
#include <iostream>

int main() {

	// Dephine base64 string

	const std::string encoded =
		"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"
		"bsKnC5978dHhU5SoQwkfrj4N9yBeixo/xxnYQ6lNSKXrZsTbcW3T1iDSA7gGNHwT4riSKBjxRbyJ"
		"zadAJx+HqfPw8/MgnocDn0HoMxj75Ogn3B/OrnQ+c/bUWa7r476Pn/mYr/sYzB+DiZwRzoTORM9k"
		"zxw7Yyg1fwjl5D/A8rupdc7fNp7u/U3j+73kNEZ2uu506PTYafW0/jTwve/zNU5hUpysm8xOjk2+"
		"OTk1eXbSNPby0Ze5H73kc5pfcr7EOY93HT9wnI8+CeYnnU9yoUeij3BHHwXzo85HfY/y333Y63y4"
		"bZHzOw8ud049ePZBjv4QfbDCEnwJuqCTNGIOtx7nZ5zPbKyGLRiWGWcnPj58uvDJ4HMvPvi7B8Wd"
		"+PigU17H9z0AZfc57nPfd8t9h+/TZ+8au+voXfzYwaMHuWdGT41y+dBKZybtdqbbVjkX+u29Rj/f"
		"a8Bt6M/fTf1LVwSjfbKzD4V27axz7mxb6Vzgr+rVY8A6FDTzTr6J7+Iz/L38Kd5o2h5a5NyGz1To"
		"bIiTQyXlQXOXs8vXxZ+cmZITHS60tjm7eWwzvym40tnets5pbnO2+dp+3vbbto/bDH1t8Bj+BZ8J"
		"ngrycnClLygHF7mCV7c7emv81b0WMPcKfnMvB1hoP+n1mWfMnNncZz5gpj/DCTdWA3o4CUcnerrd"
		"7o6TxpntHaoptEuFQ+rSbjrL23aqhkMq6d25KzwB8M3IwSNHSPM1HWp9d1iNXhPpUOMIyBQYQ0C4"
		"ZqKGNEfy+YKbDfxVj/AIzsQ94kbinnyRSub4xJ2HPN5ReaYEbipQxAFnN+UhgeoBau/JEzpRpruo"
		"RLXzmjmmXJwYYN/z34hKaloKZW5kc3RyZWFtCmVuZG9iagoKNiAwIG9iago1NDgyCmVuZG9iagoK"
		"NyAwIG9iago8PC9UeXBlL0ZvbnREZXNjcmlwdG9yL0ZvbnROYW1lL0JBQUFBQStMaWJlcmF0aW9u"
		"U2VyaWYKL0ZsYWdzIDYKL0ZvbnRCQm94Wy01NDMgLTMwMyAxMjc4IDk4Ml0vSXRhbGljQW5nbGUg"
		"MAovQXNjZW50IDg5MQovRGVzY2VudCAtMjE2Ci9DYXBIZWlnaHQgOTgxCi9TdGVtViA4MAovRm9u"
		"dEZpbGUyIDUgMCBSCj4+CmVuZG9iagoKOCAwIG9iago8PC9MZW5ndGggMjcxL0ZpbHRlci9GbGF0"
		"ZURlY29kZT4+CnN0cmVhbQp4nF2Ry27DIBBF93wFy3QRGTuO00iWpTSVJS/6UN1+AIaxi1QDwnjh"
		"vy8MaSt1ATrzuOjOkF27x04rn706I3rwdFRaOljM6gTQASalSV5QqYS/RXiLmVuSBW2/LR7mTo+m"
		"rkn2FmqLdxvdXaQZ4I5kL06CU3qiu49rH+J+tfYLZtCeMtI0VMIY3nni9pnPkKFq38lQVn7bB8lf"
		"w/tmgRYY58mKMBIWywU4ricgNWMNrdu2IaDlv1rOkmQYxSd3oTUPrYyVeRO4QD4VkQ+Jy8glcnWO"
		"fEz5Q+QKuWCRT8hHzN+nniryOWnbyJfED2js5iBajDv8GZ2K1bkwNi4a542TKg309zOssVGG5xsN"
		"x4KrCmVuZHN0cmVhbQplbmRvYmoKCjkgMCBvYmoKPDwvVHlwZS9Gb250L1N1YnR5cGUvVHJ1ZVR5"
		"cGUvQmFzZUZvbnQvQkFBQUFBK0xpYmVyYXRpb25TZXJpZgovRmlyc3RDaGFyIDAKL0xhc3RDaGFy"
		"IDEwCi9XaWR0aHNbNzc3IDcyMiAzMzMgMjc3IDI3NyAzODkgMjUwIDU1NiA1MDAgNTAwIDUwMCBd"
		"Ci9Gb250RGVzY3JpcHRvciA3IDAgUgovVG9Vbmljb2RlIDggMCBSCj4+CmVuZG9iagoKMTAgMCBv"
		"YmoKPDwvRjEgOSAwIFIKPj4KZW5kb2JqCgoxMSAwIG9iago8PC9Gb250IDEwIDAgUgovUHJvY1Nl"
		"dFsvUERGL1RleHRdCj4+CmVuZG9iagoKMSAwIG9iago8PC9UeXBlL1BhZ2UvUGFyZW50IDQgMCBS"
		"L1Jlc291cmNlcyAxMSAwIFIvTWVkaWFCb3hbMCAwIDU5NS4yNzU1OTA1NTExODEgODQxLjg2MTQx"
		"NzMyMjgzNV0vR3JvdXA8PC9TL1RyYW5zcGFyZW5jeS9DUy9EZXZpY2VSR0IvSSB0cnVlPj4vQ29u"
		"dGVudHMgMiAwIFI+PgplbmRvYmoKCjQgMCBvYmoKPDwvVHlwZS9QYWdlcwovUmVzb3VyY2VzIDEx"
		"IDAgUgovTWVkaWFCb3hbIDAgMCA1OTUgODQxIF0KL0tpZHNbIDEgMCBSIF0KL0NvdW50IDE+Pgpl"
		"bmRvYmoKCjEyIDAgb2JqCjw8L1R5cGUvQ2F0YWxvZy9QYWdlcyA0IDAgUgovT3BlbkFjdGlvblsx"
		"IDAgUiAvWFlaIG51bGwgbnVsbCAwXQovTGFuZyhsdi1MVikKPj4KZW5kb2JqCgoxMyAwIG9iago8"
		"PC9DcmVhdG9yPEZFRkYwMDU3MDA3MjAwNjkwMDc0MDA2NTAwNzI+Ci9Qcm9kdWNlcjxGRUZGMDA0"
		"QzAwNjkwMDYyMDA3MjAwNjUwMDRGMDA2NjAwNjYwMDY5MDA2MzAwNjUwMDIwMDAzNTAwMkUwMDM0"
		"PgovQ3JlYXRpb25EYXRlKEQ6MjAxODAzMTAxMDEyMjErMDInMDAnKT4+CmVuZG9iagoKeHJlZgow"
		"IDE0CjAwMDAwMDAwMDAgNjU1MzUgZiAKMDAwMDAwNjYzNiAwMDAwMCBuIAowMDAwMDAwMDE5IDAw"
		"MDAwIG4gCjAwMDAwMDAyMDcgMDAwMDAgbiAKMDAwMDAwNjgwNSAwMDAwMCBuIAowMDAwMDAwMjI3"
		"IDAwMDAwIG4gCjAwMDAwMDU3OTMgMDAwMDAgbiAKMDAwMDAwNTgxNCAwMDAwMCBuIAowMDAwMDA2"
		"MDA5IDAwMDAwIG4gCjAwMDAwMDYzNDkgMDAwMDAgbiAKMDAwMDAwNjU0OSAwMDAwMCBuIAowMDAw"
		"MDA2NTgxIDAwMDAwIG4gCjAwMDAwMDY5MDQgMDAwMDAgbiAKMDAwMDAwNzAwMSAwMDAwMCBuIAp0"
		"cmFpbGVyCjw8L1NpemUgMTQvUm9vdCAxMiAwIFIKL0luZm8gMTMgMCBSCi9JRCBbIDxBMDIxMjM5"
		"QjM4MzVGOTUwNzg4RDRCMkM2ODA2Mzk2Mz4KPEEwMjEyMzlCMzgzNUY5NTA3ODhENEIyQzY4MDYz"
		"OTYzPiBdCi9Eb2NDaGVja3N1bSAvRTdENzEzMDQxRjUxRjAwQzM5NjJERTM4QjBEREZENzAKPj4K"
		"c3RhcnR4cmVmCjcxNzYKJSVFT0YK";

	// Decoding base64 string in to the binary string

	std::string decoded = base64_decode(encoded);

	// Saving binary string in to the file

	std::ofstream ofs;
	ofs.open("decode.pdf", std::ofstream::out | std::ofstream::app | std::ios::binary);
	ofs << decoded;
	ofs.close();

	return 0;
}