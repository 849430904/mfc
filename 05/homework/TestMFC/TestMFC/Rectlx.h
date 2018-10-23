#pragma once
class CRectlx :
	public RECT
{


public:
	operator RECT* ()
	{
		return this;
	}
//���캯��
	CRectlx();
	CRectlx(int l, int t, int r, int b);
	CRectlx(const RECT& srCRectlx);
	CRectlx(LPCRECT lpSrcRect);
	CRectlx(POINT point, SIZE size);
	CRectlx(POINT topLeft, POINT bottomRight);
//��������
	~CRectlx();

	int Width() const;	//�����const �൱�������ú���Ϊֻ���������൱��c#�еķ����� get;
	int Height() const;
	CSize Size() const;

	CPoint& TopLeft();
	CPoint& BottomRight();

	const CPoint& TopLeft() const;
	const CPoint& BottomRight() const;

	CPoint CenterPoint() const;


	BOOL IsRectEmpty() const;
	BOOL IsRectNull() const;
	BOOL PtInRect(POINT point) const;
	
	void SetRect(int, int, int, int);
	void SetRect(POINT, POINT);

	

	void InflateRect(int, int);
	void DeflateRect(int, int);
	void OffsetRect(int, int);
	void NormalizeRect();

	void operator=(const RECT& srcRect);
	BOOL operator==(const RECT& rect) const;
	BOOL operator!=(const RECT& rect) const;


};

