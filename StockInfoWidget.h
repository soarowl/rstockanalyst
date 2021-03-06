/************************************************************************/
/* 文件名称：StockInfoWidget.h
/* 创建时间：2012-12-13 17:55
/*
/* 描    述：用于显示单只股票的行情信息，继承自CBaseWidget
/************************************************************************/
#ifndef STOCK_INFO_WIDGET_H
#define STOCK_INFO_WIDGET_H
#include "BaseWidget.h"
#include "StockInfoItem.h"

class CStockInfoWidget : public CBaseWidget
{
	Q_OBJECT
public:
	CStockInfoWidget(CBaseWidget* parent = 0);
	~CStockInfoWidget(void);

public:
	//加载该K线图的配置信息
	virtual bool loadPanelInfo(const QDomElement& eleWidget);
	//保存该K线图的配置信息
	virtual bool savePanelInfo(QDomDocument& doc,QDomElement& eleWidget);

public:
	//通过查找keyword获取需要在按键精灵上显示的数据
	virtual void getKeyWizData(const QString& keyword,QList<KeyWizData*>& listRet);
	//键盘精灵窗口确认后触发
	virtual void keyWizEntered(KeyWizData* pData);

public slots:
	virtual void setStockCode(const QString& only);
	void updateStockInfo(const QString& only);

protected:
	void setStockItem(CStockInfoItem* pItem);

protected:
	virtual void paintEvent(QPaintEvent* e);				//绘制事件
	virtual void keyPressEvent(QKeyEvent* e);				//键盘操作

	//虚函数，各个控件的自定义菜单。
	virtual QMenu* getCustomMenu();

protected slots:
	void onSetStockCode();								//弹出对话框，让用户手动输入股票代码

private:
	QMenu* m_pMenuCustom;					//自定义菜单

	CStockInfoItem* m_pStockItem;

private:
	/*绘制窗口所用到的成员变量*/
	int m_iItemHeight;						//单行的高度
	QColor m_clrGrid;						//分隔线所用颜色
	QColor m_clrTitle;						//标题颜色
	QColor m_clrDesc;						//描述信息所用颜色
	QColor m_clrDataRed;					//数据增长所用颜色
	QColor m_clrDataBlue;					//数据下降所用颜色
	QColor m_clrDataNone;					//数据正常状态
};


#endif	//STOCK_INFO_WIDGET_H