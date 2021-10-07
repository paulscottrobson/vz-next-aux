//
//	This file is automatically generated
//
case 0x00: /**** $00:rlc b ****/
	B = SRRLC(B);
	cycles -= 8;break;

case 0x01: /**** $01:rlc c ****/
	C = SRRLC(C);
	cycles -= 8;break;

case 0x02: /**** $02:rlc d ****/
	D = SRRLC(D);
	cycles -= 8;break;

case 0x03: /**** $03:rlc e ****/
	E = SRRLC(E);
	cycles -= 8;break;

case 0x04: /**** $04:rlc h ****/
	H = SRRLC(H);
	cycles -= 8;break;

case 0x05: /**** $05:rlc l ****/
	L = SRRLC(L);
	cycles -= 8;break;

case 0x06: /**** $06:rlc (hl) ****/
	temp8 = READ8(HL()); temp8 = SRRLC(temp8); WRITE8(HL(),temp8);;
	cycles -= 15;break;

case 0x07: /**** $07:rlc a ****/
	A = SRRLC(A);
	cycles -= 8;break;

case 0x08: /**** $08:rrc b ****/
	B = SRRRC(B);
	cycles -= 8;break;

case 0x09: /**** $09:rrc c ****/
	C = SRRRC(C);
	cycles -= 8;break;

case 0x0a: /**** $0a:rrc d ****/
	D = SRRRC(D);
	cycles -= 8;break;

case 0x0b: /**** $0b:rrc e ****/
	E = SRRRC(E);
	cycles -= 8;break;

case 0x0c: /**** $0c:rrc h ****/
	H = SRRRC(H);
	cycles -= 8;break;

case 0x0d: /**** $0d:rrc l ****/
	L = SRRRC(L);
	cycles -= 8;break;

case 0x0e: /**** $0e:rrc (hl) ****/
	temp8 = READ8(HL()); temp8 = SRRRC(temp8); WRITE8(HL(),temp8);;
	cycles -= 15;break;

case 0x0f: /**** $0f:rrc a ****/
	A = SRRRC(A);
	cycles -= 8;break;

case 0x10: /**** $10:rl b ****/
	B = SRRL(B);
	cycles -= 8;break;

case 0x11: /**** $11:rl c ****/
	C = SRRL(C);
	cycles -= 8;break;

case 0x12: /**** $12:rl d ****/
	D = SRRL(D);
	cycles -= 8;break;

case 0x13: /**** $13:rl e ****/
	E = SRRL(E);
	cycles -= 8;break;

case 0x14: /**** $14:rl h ****/
	H = SRRL(H);
	cycles -= 8;break;

case 0x15: /**** $15:rl l ****/
	L = SRRL(L);
	cycles -= 8;break;

case 0x16: /**** $16:rl (hl) ****/
	temp8 = READ8(HL()); temp8 = SRRL(temp8); WRITE8(HL(),temp8);;
	cycles -= 15;break;

case 0x17: /**** $17:rl a ****/
	A = SRRL(A);
	cycles -= 8;break;

case 0x18: /**** $18:rr b ****/
	B = SRRR(B);
	cycles -= 8;break;

case 0x19: /**** $19:rr c ****/
	C = SRRR(C);
	cycles -= 8;break;

case 0x1a: /**** $1a:rr d ****/
	D = SRRR(D);
	cycles -= 8;break;

case 0x1b: /**** $1b:rr e ****/
	E = SRRR(E);
	cycles -= 8;break;

case 0x1c: /**** $1c:rr h ****/
	H = SRRR(H);
	cycles -= 8;break;

case 0x1d: /**** $1d:rr l ****/
	L = SRRR(L);
	cycles -= 8;break;

case 0x1e: /**** $1e:rr (hl) ****/
	temp8 = READ8(HL()); temp8 = SRRR(temp8); WRITE8(HL(),temp8);;
	cycles -= 15;break;

case 0x1f: /**** $1f:rr a ****/
	A = SRRR(A);
	cycles -= 8;break;

case 0x20: /**** $20:sla b ****/
	B = SRSLA(B);
	cycles -= 8;break;

case 0x21: /**** $21:sla c ****/
	C = SRSLA(C);
	cycles -= 8;break;

case 0x22: /**** $22:sla d ****/
	D = SRSLA(D);
	cycles -= 8;break;

case 0x23: /**** $23:sla e ****/
	E = SRSLA(E);
	cycles -= 8;break;

case 0x24: /**** $24:sla h ****/
	H = SRSLA(H);
	cycles -= 8;break;

case 0x25: /**** $25:sla l ****/
	L = SRSLA(L);
	cycles -= 8;break;

case 0x26: /**** $26:sla (hl) ****/
	temp8 = READ8(HL()); temp8 = SRSLA(temp8); WRITE8(HL(),temp8);;
	cycles -= 15;break;

case 0x27: /**** $27:sla a ****/
	A = SRSLA(A);
	cycles -= 8;break;

case 0x28: /**** $28:sra b ****/
	B = SRSRA(B);
	cycles -= 8;break;

case 0x29: /**** $29:sra c ****/
	C = SRSRA(C);
	cycles -= 8;break;

case 0x2a: /**** $2a:sra d ****/
	D = SRSRA(D);
	cycles -= 8;break;

case 0x2b: /**** $2b:sra e ****/
	E = SRSRA(E);
	cycles -= 8;break;

case 0x2c: /**** $2c:sra h ****/
	H = SRSRA(H);
	cycles -= 8;break;

case 0x2d: /**** $2d:sra l ****/
	L = SRSRA(L);
	cycles -= 8;break;

case 0x2e: /**** $2e:sra (hl) ****/
	temp8 = READ8(HL()); temp8 = SRSRA(temp8); WRITE8(HL(),temp8);;
	cycles -= 15;break;

case 0x2f: /**** $2f:sra a ****/
	A = SRSRA(A);
	cycles -= 8;break;

case 0x38: /**** $38:srl b ****/
	B = SRSRL(B);
	cycles -= 8;break;

case 0x39: /**** $39:srl c ****/
	C = SRSRL(C);
	cycles -= 8;break;

case 0x3a: /**** $3a:srl d ****/
	D = SRSRL(D);
	cycles -= 8;break;

case 0x3b: /**** $3b:srl e ****/
	E = SRSRL(E);
	cycles -= 8;break;

case 0x3c: /**** $3c:srl h ****/
	H = SRSRL(H);
	cycles -= 8;break;

case 0x3d: /**** $3d:srl l ****/
	L = SRSRL(L);
	cycles -= 8;break;

case 0x3e: /**** $3e:srl (hl) ****/
	temp8 = READ8(HL()); temp8 = SRSRL(temp8); WRITE8(HL(),temp8);;
	cycles -= 15;break;

case 0x3f: /**** $3f:srl a ****/
	A = SRSRL(A);
	cycles -= 8;break;

case 0x40: /**** $40:bit 0,b ****/
	bitOp(B & 1);
	cycles -= 8;break;

case 0x41: /**** $41:bit 0,c ****/
	bitOp(C & 1);
	cycles -= 8;break;

case 0x42: /**** $42:bit 0,d ****/
	bitOp(D & 1);
	cycles -= 8;break;

case 0x43: /**** $43:bit 0,e ****/
	bitOp(E & 1);
	cycles -= 8;break;

case 0x44: /**** $44:bit 0,h ****/
	bitOp(H & 1);
	cycles -= 8;break;

case 0x45: /**** $45:bit 0,l ****/
	bitOp(L & 1);
	cycles -= 8;break;

case 0x46: /**** $46:bit 0,(hl) ****/
	bitOp(READ8(HL()) & 1);
	cycles -= 12;break;

case 0x47: /**** $47:bit 0,a ****/
	bitOp(A & 1);
	cycles -= 8;break;

case 0x48: /**** $48:bit 1,b ****/
	bitOp(B & 2);
	cycles -= 8;break;

case 0x49: /**** $49:bit 1,c ****/
	bitOp(C & 2);
	cycles -= 8;break;

case 0x4a: /**** $4a:bit 1,d ****/
	bitOp(D & 2);
	cycles -= 8;break;

case 0x4b: /**** $4b:bit 1,e ****/
	bitOp(E & 2);
	cycles -= 8;break;

case 0x4c: /**** $4c:bit 1,h ****/
	bitOp(H & 2);
	cycles -= 8;break;

case 0x4d: /**** $4d:bit 1,l ****/
	bitOp(L & 2);
	cycles -= 8;break;

case 0x4e: /**** $4e:bit 1,(hl) ****/
	bitOp(READ8(HL()) & 2);
	cycles -= 12;break;

case 0x4f: /**** $4f:bit 1,a ****/
	bitOp(A & 2);
	cycles -= 8;break;

case 0x50: /**** $50:bit 2,b ****/
	bitOp(B & 4);
	cycles -= 8;break;

case 0x51: /**** $51:bit 2,c ****/
	bitOp(C & 4);
	cycles -= 8;break;

case 0x52: /**** $52:bit 2,d ****/
	bitOp(D & 4);
	cycles -= 8;break;

case 0x53: /**** $53:bit 2,e ****/
	bitOp(E & 4);
	cycles -= 8;break;

case 0x54: /**** $54:bit 2,h ****/
	bitOp(H & 4);
	cycles -= 8;break;

case 0x55: /**** $55:bit 2,l ****/
	bitOp(L & 4);
	cycles -= 8;break;

case 0x56: /**** $56:bit 2,(hl) ****/
	bitOp(READ8(HL()) & 4);
	cycles -= 12;break;

case 0x57: /**** $57:bit 2,a ****/
	bitOp(A & 4);
	cycles -= 8;break;

case 0x58: /**** $58:bit 3,b ****/
	bitOp(B & 8);
	cycles -= 8;break;

case 0x59: /**** $59:bit 3,c ****/
	bitOp(C & 8);
	cycles -= 8;break;

case 0x5a: /**** $5a:bit 3,d ****/
	bitOp(D & 8);
	cycles -= 8;break;

case 0x5b: /**** $5b:bit 3,e ****/
	bitOp(E & 8);
	cycles -= 8;break;

case 0x5c: /**** $5c:bit 3,h ****/
	bitOp(H & 8);
	cycles -= 8;break;

case 0x5d: /**** $5d:bit 3,l ****/
	bitOp(L & 8);
	cycles -= 8;break;

case 0x5e: /**** $5e:bit 3,(hl) ****/
	bitOp(READ8(HL()) & 8);
	cycles -= 12;break;

case 0x5f: /**** $5f:bit 3,a ****/
	bitOp(A & 8);
	cycles -= 8;break;

case 0x60: /**** $60:bit 4,b ****/
	bitOp(B & 16);
	cycles -= 8;break;

case 0x61: /**** $61:bit 4,c ****/
	bitOp(C & 16);
	cycles -= 8;break;

case 0x62: /**** $62:bit 4,d ****/
	bitOp(D & 16);
	cycles -= 8;break;

case 0x63: /**** $63:bit 4,e ****/
	bitOp(E & 16);
	cycles -= 8;break;

case 0x64: /**** $64:bit 4,h ****/
	bitOp(H & 16);
	cycles -= 8;break;

case 0x65: /**** $65:bit 4,l ****/
	bitOp(L & 16);
	cycles -= 8;break;

case 0x66: /**** $66:bit 4,(hl) ****/
	bitOp(READ8(HL()) & 16);
	cycles -= 12;break;

case 0x67: /**** $67:bit 4,a ****/
	bitOp(A & 16);
	cycles -= 8;break;

case 0x68: /**** $68:bit 5,b ****/
	bitOp(B & 32);
	cycles -= 8;break;

case 0x69: /**** $69:bit 5,c ****/
	bitOp(C & 32);
	cycles -= 8;break;

case 0x6a: /**** $6a:bit 5,d ****/
	bitOp(D & 32);
	cycles -= 8;break;

case 0x6b: /**** $6b:bit 5,e ****/
	bitOp(E & 32);
	cycles -= 8;break;

case 0x6c: /**** $6c:bit 5,h ****/
	bitOp(H & 32);
	cycles -= 8;break;

case 0x6d: /**** $6d:bit 5,l ****/
	bitOp(L & 32);
	cycles -= 8;break;

case 0x6e: /**** $6e:bit 5,(hl) ****/
	bitOp(READ8(HL()) & 32);
	cycles -= 12;break;

case 0x6f: /**** $6f:bit 5,a ****/
	bitOp(A & 32);
	cycles -= 8;break;

case 0x70: /**** $70:bit 6,b ****/
	bitOp(B & 64);
	cycles -= 8;break;

case 0x71: /**** $71:bit 6,c ****/
	bitOp(C & 64);
	cycles -= 8;break;

case 0x72: /**** $72:bit 6,d ****/
	bitOp(D & 64);
	cycles -= 8;break;

case 0x73: /**** $73:bit 6,e ****/
	bitOp(E & 64);
	cycles -= 8;break;

case 0x74: /**** $74:bit 6,h ****/
	bitOp(H & 64);
	cycles -= 8;break;

case 0x75: /**** $75:bit 6,l ****/
	bitOp(L & 64);
	cycles -= 8;break;

case 0x76: /**** $76:bit 6,(hl) ****/
	bitOp(READ8(HL()) & 64);
	cycles -= 12;break;

case 0x77: /**** $77:bit 6,a ****/
	bitOp(A & 64);
	cycles -= 8;break;

case 0x78: /**** $78:bit 7,b ****/
	bitOp(B & 128);
	cycles -= 8;break;

case 0x79: /**** $79:bit 7,c ****/
	bitOp(C & 128);
	cycles -= 8;break;

case 0x7a: /**** $7a:bit 7,d ****/
	bitOp(D & 128);
	cycles -= 8;break;

case 0x7b: /**** $7b:bit 7,e ****/
	bitOp(E & 128);
	cycles -= 8;break;

case 0x7c: /**** $7c:bit 7,h ****/
	bitOp(H & 128);
	cycles -= 8;break;

case 0x7d: /**** $7d:bit 7,l ****/
	bitOp(L & 128);
	cycles -= 8;break;

case 0x7e: /**** $7e:bit 7,(hl) ****/
	bitOp(READ8(HL()) & 128);
	cycles -= 12;break;

case 0x7f: /**** $7f:bit 7,a ****/
	bitOp(A & 128);
	cycles -= 8;break;

case 0x80: /**** $80:res 0,b ****/
	B &= (~1);
	cycles -= 8;break;

case 0x81: /**** $81:res 0,c ****/
	C &= (~1);
	cycles -= 8;break;

case 0x82: /**** $82:res 0,d ****/
	D &= (~1);
	cycles -= 8;break;

case 0x83: /**** $83:res 0,e ****/
	E &= (~1);
	cycles -= 8;break;

case 0x84: /**** $84:res 0,h ****/
	H &= (~1);
	cycles -= 8;break;

case 0x85: /**** $85:res 0,l ****/
	L &= (~1);
	cycles -= 8;break;

case 0x86: /**** $86:res 0,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8 & (~1));;
	cycles -= 12;break;

case 0x87: /**** $87:res 0,a ****/
	A &= (~1);
	cycles -= 8;break;

case 0x88: /**** $88:res 1,b ****/
	B &= (~2);
	cycles -= 8;break;

case 0x89: /**** $89:res 1,c ****/
	C &= (~2);
	cycles -= 8;break;

case 0x8a: /**** $8a:res 1,d ****/
	D &= (~2);
	cycles -= 8;break;

case 0x8b: /**** $8b:res 1,e ****/
	E &= (~2);
	cycles -= 8;break;

case 0x8c: /**** $8c:res 1,h ****/
	H &= (~2);
	cycles -= 8;break;

case 0x8d: /**** $8d:res 1,l ****/
	L &= (~2);
	cycles -= 8;break;

case 0x8e: /**** $8e:res 1,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8 & (~2));;
	cycles -= 12;break;

case 0x8f: /**** $8f:res 1,a ****/
	A &= (~2);
	cycles -= 8;break;

case 0x90: /**** $90:res 2,b ****/
	B &= (~4);
	cycles -= 8;break;

case 0x91: /**** $91:res 2,c ****/
	C &= (~4);
	cycles -= 8;break;

case 0x92: /**** $92:res 2,d ****/
	D &= (~4);
	cycles -= 8;break;

case 0x93: /**** $93:res 2,e ****/
	E &= (~4);
	cycles -= 8;break;

case 0x94: /**** $94:res 2,h ****/
	H &= (~4);
	cycles -= 8;break;

case 0x95: /**** $95:res 2,l ****/
	L &= (~4);
	cycles -= 8;break;

case 0x96: /**** $96:res 2,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8 & (~4));;
	cycles -= 12;break;

case 0x97: /**** $97:res 2,a ****/
	A &= (~4);
	cycles -= 8;break;

case 0x98: /**** $98:res 3,b ****/
	B &= (~8);
	cycles -= 8;break;

case 0x99: /**** $99:res 3,c ****/
	C &= (~8);
	cycles -= 8;break;

case 0x9a: /**** $9a:res 3,d ****/
	D &= (~8);
	cycles -= 8;break;

case 0x9b: /**** $9b:res 3,e ****/
	E &= (~8);
	cycles -= 8;break;

case 0x9c: /**** $9c:res 3,h ****/
	H &= (~8);
	cycles -= 8;break;

case 0x9d: /**** $9d:res 3,l ****/
	L &= (~8);
	cycles -= 8;break;

case 0x9e: /**** $9e:res 3,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8 & (~8));;
	cycles -= 12;break;

case 0x9f: /**** $9f:res 3,a ****/
	A &= (~8);
	cycles -= 8;break;

case 0xa0: /**** $a0:res 4,b ****/
	B &= (~16);
	cycles -= 8;break;

case 0xa1: /**** $a1:res 4,c ****/
	C &= (~16);
	cycles -= 8;break;

case 0xa2: /**** $a2:res 4,d ****/
	D &= (~16);
	cycles -= 8;break;

case 0xa3: /**** $a3:res 4,e ****/
	E &= (~16);
	cycles -= 8;break;

case 0xa4: /**** $a4:res 4,h ****/
	H &= (~16);
	cycles -= 8;break;

case 0xa5: /**** $a5:res 4,l ****/
	L &= (~16);
	cycles -= 8;break;

case 0xa6: /**** $a6:res 4,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8 & (~16));;
	cycles -= 12;break;

case 0xa7: /**** $a7:res 4,a ****/
	A &= (~16);
	cycles -= 8;break;

case 0xa8: /**** $a8:res 5,b ****/
	B &= (~32);
	cycles -= 8;break;

case 0xa9: /**** $a9:res 5,c ****/
	C &= (~32);
	cycles -= 8;break;

case 0xaa: /**** $aa:res 5,d ****/
	D &= (~32);
	cycles -= 8;break;

case 0xab: /**** $ab:res 5,e ****/
	E &= (~32);
	cycles -= 8;break;

case 0xac: /**** $ac:res 5,h ****/
	H &= (~32);
	cycles -= 8;break;

case 0xad: /**** $ad:res 5,l ****/
	L &= (~32);
	cycles -= 8;break;

case 0xae: /**** $ae:res 5,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8 & (~32));;
	cycles -= 12;break;

case 0xaf: /**** $af:res 5,a ****/
	A &= (~32);
	cycles -= 8;break;

case 0xb0: /**** $b0:res 6,b ****/
	B &= (~64);
	cycles -= 8;break;

case 0xb1: /**** $b1:res 6,c ****/
	C &= (~64);
	cycles -= 8;break;

case 0xb2: /**** $b2:res 6,d ****/
	D &= (~64);
	cycles -= 8;break;

case 0xb3: /**** $b3:res 6,e ****/
	E &= (~64);
	cycles -= 8;break;

case 0xb4: /**** $b4:res 6,h ****/
	H &= (~64);
	cycles -= 8;break;

case 0xb5: /**** $b5:res 6,l ****/
	L &= (~64);
	cycles -= 8;break;

case 0xb6: /**** $b6:res 6,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8 & (~64));;
	cycles -= 12;break;

case 0xb7: /**** $b7:res 6,a ****/
	A &= (~64);
	cycles -= 8;break;

case 0xb8: /**** $b8:res 7,b ****/
	B &= (~128);
	cycles -= 8;break;

case 0xb9: /**** $b9:res 7,c ****/
	C &= (~128);
	cycles -= 8;break;

case 0xba: /**** $ba:res 7,d ****/
	D &= (~128);
	cycles -= 8;break;

case 0xbb: /**** $bb:res 7,e ****/
	E &= (~128);
	cycles -= 8;break;

case 0xbc: /**** $bc:res 7,h ****/
	H &= (~128);
	cycles -= 8;break;

case 0xbd: /**** $bd:res 7,l ****/
	L &= (~128);
	cycles -= 8;break;

case 0xbe: /**** $be:res 7,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8 & (~128));;
	cycles -= 12;break;

case 0xbf: /**** $bf:res 7,a ****/
	A &= (~128);
	cycles -= 8;break;

case 0xc0: /**** $c0:set 0,b ****/
	B |= 1;
	cycles -= 8;break;

case 0xc1: /**** $c1:set 0,c ****/
	C |= 1;
	cycles -= 8;break;

case 0xc2: /**** $c2:set 0,d ****/
	D |= 1;
	cycles -= 8;break;

case 0xc3: /**** $c3:set 0,e ****/
	E |= 1;
	cycles -= 8;break;

case 0xc4: /**** $c4:set 0,h ****/
	H |= 1;
	cycles -= 8;break;

case 0xc5: /**** $c5:set 0,l ****/
	L |= 1;
	cycles -= 8;break;

case 0xc6: /**** $c6:set 0,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8|1);;
	cycles -= 12;break;

case 0xc7: /**** $c7:set 0,a ****/
	A |= 1;
	cycles -= 8;break;

case 0xc8: /**** $c8:set 1,b ****/
	B |= 2;
	cycles -= 8;break;

case 0xc9: /**** $c9:set 1,c ****/
	C |= 2;
	cycles -= 8;break;

case 0xca: /**** $ca:set 1,d ****/
	D |= 2;
	cycles -= 8;break;

case 0xcb: /**** $cb:set 1,e ****/
	E |= 2;
	cycles -= 8;break;

case 0xcc: /**** $cc:set 1,h ****/
	H |= 2;
	cycles -= 8;break;

case 0xcd: /**** $cd:set 1,l ****/
	L |= 2;
	cycles -= 8;break;

case 0xce: /**** $ce:set 1,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8|2);;
	cycles -= 12;break;

case 0xcf: /**** $cf:set 1,a ****/
	A |= 2;
	cycles -= 8;break;

case 0xd0: /**** $d0:set 2,b ****/
	B |= 4;
	cycles -= 8;break;

case 0xd1: /**** $d1:set 2,c ****/
	C |= 4;
	cycles -= 8;break;

case 0xd2: /**** $d2:set 2,d ****/
	D |= 4;
	cycles -= 8;break;

case 0xd3: /**** $d3:set 2,e ****/
	E |= 4;
	cycles -= 8;break;

case 0xd4: /**** $d4:set 2,h ****/
	H |= 4;
	cycles -= 8;break;

case 0xd5: /**** $d5:set 2,l ****/
	L |= 4;
	cycles -= 8;break;

case 0xd6: /**** $d6:set 2,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8|4);;
	cycles -= 12;break;

case 0xd7: /**** $d7:set 2,a ****/
	A |= 4;
	cycles -= 8;break;

case 0xd8: /**** $d8:set 3,b ****/
	B |= 8;
	cycles -= 8;break;

case 0xd9: /**** $d9:set 3,c ****/
	C |= 8;
	cycles -= 8;break;

case 0xda: /**** $da:set 3,d ****/
	D |= 8;
	cycles -= 8;break;

case 0xdb: /**** $db:set 3,e ****/
	E |= 8;
	cycles -= 8;break;

case 0xdc: /**** $dc:set 3,h ****/
	H |= 8;
	cycles -= 8;break;

case 0xdd: /**** $dd:set 3,l ****/
	L |= 8;
	cycles -= 8;break;

case 0xde: /**** $de:set 3,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8|8);;
	cycles -= 12;break;

case 0xdf: /**** $df:set 3,a ****/
	A |= 8;
	cycles -= 8;break;

case 0xe0: /**** $e0:set 4,b ****/
	B |= 16;
	cycles -= 8;break;

case 0xe1: /**** $e1:set 4,c ****/
	C |= 16;
	cycles -= 8;break;

case 0xe2: /**** $e2:set 4,d ****/
	D |= 16;
	cycles -= 8;break;

case 0xe3: /**** $e3:set 4,e ****/
	E |= 16;
	cycles -= 8;break;

case 0xe4: /**** $e4:set 4,h ****/
	H |= 16;
	cycles -= 8;break;

case 0xe5: /**** $e5:set 4,l ****/
	L |= 16;
	cycles -= 8;break;

case 0xe6: /**** $e6:set 4,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8|16);;
	cycles -= 12;break;

case 0xe7: /**** $e7:set 4,a ****/
	A |= 16;
	cycles -= 8;break;

case 0xe8: /**** $e8:set 5,b ****/
	B |= 32;
	cycles -= 8;break;

case 0xe9: /**** $e9:set 5,c ****/
	C |= 32;
	cycles -= 8;break;

case 0xea: /**** $ea:set 5,d ****/
	D |= 32;
	cycles -= 8;break;

case 0xeb: /**** $eb:set 5,e ****/
	E |= 32;
	cycles -= 8;break;

case 0xec: /**** $ec:set 5,h ****/
	H |= 32;
	cycles -= 8;break;

case 0xed: /**** $ed:set 5,l ****/
	L |= 32;
	cycles -= 8;break;

case 0xee: /**** $ee:set 5,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8|32);;
	cycles -= 12;break;

case 0xef: /**** $ef:set 5,a ****/
	A |= 32;
	cycles -= 8;break;

case 0xf0: /**** $f0:set 6,b ****/
	B |= 64;
	cycles -= 8;break;

case 0xf1: /**** $f1:set 6,c ****/
	C |= 64;
	cycles -= 8;break;

case 0xf2: /**** $f2:set 6,d ****/
	D |= 64;
	cycles -= 8;break;

case 0xf3: /**** $f3:set 6,e ****/
	E |= 64;
	cycles -= 8;break;

case 0xf4: /**** $f4:set 6,h ****/
	H |= 64;
	cycles -= 8;break;

case 0xf5: /**** $f5:set 6,l ****/
	L |= 64;
	cycles -= 8;break;

case 0xf6: /**** $f6:set 6,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8|64);;
	cycles -= 12;break;

case 0xf7: /**** $f7:set 6,a ****/
	A |= 64;
	cycles -= 8;break;

case 0xf8: /**** $f8:set 7,b ****/
	B |= 128;
	cycles -= 8;break;

case 0xf9: /**** $f9:set 7,c ****/
	C |= 128;
	cycles -= 8;break;

case 0xfa: /**** $fa:set 7,d ****/
	D |= 128;
	cycles -= 8;break;

case 0xfb: /**** $fb:set 7,e ****/
	E |= 128;
	cycles -= 8;break;

case 0xfc: /**** $fc:set 7,h ****/
	H |= 128;
	cycles -= 8;break;

case 0xfd: /**** $fd:set 7,l ****/
	L |= 128;
	cycles -= 8;break;

case 0xfe: /**** $fe:set 7,(hl) ****/
	temp8 = READ8(HL()); WRITE8(HL(),temp8|128);;
	cycles -= 12;break;

case 0xff: /**** $ff:set 7,a ****/
	A |= 128;
	cycles -= 8;break;


