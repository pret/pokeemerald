#ifndef GUARD_KOREAN_H
#define GUARD_KOREAN_H

/**
 * 한글 문자 검사
 *
 * @param glyph 문자값
 * @return 한글일 경우 TRUE
 */
u8 CheckKoreanGlyph(u16 glyph);

/**
 * 문자가 자음인지 검사
 *
 * @param glyph 문자값
 * @return 자음일 경우 TRUE
 */
u8 CheckJaum(u8 glyph);

/**
 * 문자가 모음인지 검사
 *
 * @param glyph 문자값
 * @return 모음일 경우 TRUE
 */
u8 CheckMoum(u8 glyph);

/**
 * 한글 고유번호를 유니코드로 변환(0xac00를 빼준 결과 반환)
 *
 * @param korean 입력값
 * @return 유니코드값
 */
u16 ConvertKoreanToUnicode(u16 korean);

/**
 * 유니코드를 한글 고유번호로 변환
 *
 * @param code 입력값
 * @return 한글 고유번호 반환
 */
u16 ConvertUnicodeToKorean(u16 code);

/**
 * 입력값을 초성값으로 변환
 *
 * @param index 입력값
 * @return 초성값 반환
 */
u8 GetCho(u8 index);

/**
 * 입력값을 중성값으로 변환
 *
 * @param index 입력값
 * @return 중성값 반환
 */
u8 GetJung(u8 index);

/**
 * 입력값을 종성값으로 변환
 *
 * @param index 입력값
 * @return 종성값 반환, -1 반환시 실패
 */
u8 GetJong(u8 index);

/**
 * 초성값으로 변환시키기
 *
 * @param korean 입력값
 * @return 초성값 반환
 */
u8 ConvertToCho(u16 korean);

/**
 * 종성값에서 초성값으로 변환시키기
 *
 * @param jong 입력값
 * @return 초성값 반환
 */
u8 ConvertJongToCho(u8 jong);

/**
 * 중성값으로 변환시키기
 *
 * @param korean 입력값
 * @return 중성값 반환
 */
u8 ConvertToJung(u16 korean);

/**
 * 종성값으로 변환시키기
 *
 * @param korean 입력값
 * @return 종성값 반환
 */
u8 ConvertToJong(u16 korean);

/**
 * 종성값 인덱스으로 변환시키기
 * (자음값이 아닌 종성값에 대한 순서값)
 *
 * @param korean 입력값
 * @return 종성값 인덱스 반환
 */
u8 ConvertToJongIndex(u16 korean);

/**
 * 한글 조합하기
 *
 * @param cho  초성값
 * @param jung 중성값
 * @param jong 종성값
 * @return 유니코드 한글문자 반환
 */
u16 GetKorean(u8 cho, u8 jung, u8 jong);

/**
 * 자음 합치기
 *
 * @param ch  자음값 1
 * @param ch2 자음값 2
 * @return 합쳐진 자음값 반환, 실패시 0 반환
 */
u8 MergeJaum(u8 ch, u8 ch2);

/**
 * 모음 합치기
 *
 * @param ch  모음값 1
 * @param ch2 모음값 2
 * @return 합쳐진 모음값 반환, 실패시 0 반환
 */
u8 MergeMoum(u8 ch, u8 ch2);

/**
 * 종성 분리하기
 *
 * @param ch    종성값
 * @param index 반환할 위치값
 * @return 분리된 종성 반환, 실패시 0 반환
 */
u8 SplitJong(u8 ch, u8 index);

/**
 * 현재 위치의 문자가 종성이 있는지 검사한다.
 *
 * @param ch 문자값
 * @return 종성 유무
 */
bool8 CheckHasJongSeong(u16 ch);

/**
 * 한글 폰트 처리, 출력할 한글의 index를 반환한다.
 *
 * @param textPrinter 종성값
 * @param currChar    현재 글자 index
 * @return 한글 index
 */
u16 GetKoreanChar(struct TextPrinter *textPrinter, u16 currChar);

#endif
