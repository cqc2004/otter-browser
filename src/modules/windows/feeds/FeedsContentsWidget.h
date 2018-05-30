/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2018 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_FEEDSCONTENTSWIDGET_H
#define OTTER_FEEDSCONTENTSWIDGET_H

#include "../../../core/FeedsManager.h"
#include "../../../ui/ContentsWidget.h"

namespace Otter
{

namespace Ui
{
	class FeedsContentsWidget;
}

class Window;

class FeedsContentsWidget final : public ContentsWidget
{
	Q_OBJECT

public:
	enum DataRole
	{
		UrlRole = Qt::StatusTipRole,
		IdentifierRole = Qt::UserRole,
		SummaryRole,
		ContentRole,
		AuthorRole,
		EmailRole,
		PublicationTimeRole,
		UpdateTimeRole,
		CategoriesRole
	};

	explicit FeedsContentsWidget(const QVariantMap &parameters, QWidget *parent);
	~FeedsContentsWidget();

	QString getTitle() const override;
	QLatin1String getType() const override;
	QUrl getUrl() const override;
	QIcon getIcon() const override;
	bool eventFilter(QObject *object, QEvent *event);

public slots:
	void setUrl(const QUrl &url, bool isTyped = true) override;

protected:
	void changeEvent(QEvent *event) override;
	void setFeed(Feed *feed);
	FeedsModel::Entry* findFolder(const QModelIndex &index) const;

protected slots:
	void addFeed();
	void addFolder();
	void updateFeed();
	void removeFeed();
	void openFeed();
	void subscribeFeed();
	void feedProperties();
	void selectCategory();
	void toggleCategory(QAction *action);
	void showContextMenu(const QPoint &position);
	void updateActions();
	void updateEntry();
	void updateFeedModel();

private:
	Feed *m_feed;
	QStandardItemModel *m_feedModel;
	QStringList m_categories;
	Ui::FeedsContentsWidget *m_ui;
};

}

#endif
