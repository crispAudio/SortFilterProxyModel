#ifndef QQMLSORTFILTERPROXYMODEL_H
#define QQMLSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QQmlParserStatus>

class QQmlSortFilterProxyModel : public QSortFilterProxyModel, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)

    Q_PROPERTY(int count READ count NOTIFY countChanged)

    Q_PROPERTY(QString filterRoleName READ filterRoleName WRITE setFilterRoleName NOTIFY filterRoleNameChanged)
    Q_PROPERTY(QString filterPattern READ filterPattern WRITE setFilterPattern NOTIFY filterPatternChanged)
    Q_PROPERTY(PatternSyntax filterPatternSyntax READ filterPatternSyntax WRITE setFilterPatternSyntax NOTIFY filterPatternSyntaxChanged)
    Q_PROPERTY(QVariant filterValue READ filterValue WRITE setFilterValue NOTIFY filterValueChanged)

    Q_PROPERTY(QString sortRoleName READ sortRoleName WRITE setSortRoleName NOTIFY sortRoleNameChanged)
    Q_PROPERTY(Qt::SortOrder sortOrder READ sortOrder WRITE setSortOrder)

public:
    enum PatternSyntax {
        RegExp = QRegExp::RegExp,
        Wildcard = QRegExp::Wildcard,
        FixedString = QRegExp::FixedString,
        RegExp2 = QRegExp::RegExp2,
        WildcardUnix = QRegExp::WildcardUnix,
        W3CXmlSchema11 = QRegExp::W3CXmlSchema11 };
    Q_ENUMS(PatternSyntax)

    QQmlSortFilterProxyModel(QObject* parent = 0);

    int count() const;

    const QString& filterRoleName() const;
    void setFilterRoleName(const QString& filterRoleName);

    QString filterPattern() const;
    void setFilterPattern(const QString& filterPattern);

    PatternSyntax filterPatternSyntax() const;
    void setFilterPatternSyntax(PatternSyntax patternSyntax);

    const QVariant& filterValue() const;
    void setFilterValue(const QVariant& filterValue);

    const QString& sortRoleName() const;
    void setSortRoleName(const QString& sortRoleName);

    void setSortOrder(Qt::SortOrder sortOrder);

    void classBegin() override;
    void componentComplete() override;

signals:
    void countChanged();

    void filterRoleNameChanged();
    void filterPatternSyntaxChanged();
    void filterPatternChanged();
    void filterValueChanged();

    void sortRoleNameChanged();

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex& source_parent) const override;
    bool lessThan(const QModelIndex& source_left, const QModelIndex& source_right) const override;

private slots:
    void invalidateFilter();
    void invalidate();
    void updateFilterRole();
    void updateSortRole();
    void updateRoles();

private:
    QVariantMap modelDataMap(const QModelIndex& modelIndex) const;

    QString m_filterRoleName;
    QVariant m_filterValue;
    QString m_sortRoleName;
    bool m_completed = false;
};

#endif // QQMLSORTFILTERPROXYMODEL_H
