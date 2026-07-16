#ifndef REVISION_H
#define REVISION_H

#include <QDateTime>
#include <QString>
#include <QUuid>

#include <optional>

enum class RevisionState
{
    Working,
    Committed
};

struct Revision
{
    QUuid id;
    QUuid projectId;
    std::optional<QUuid> parentRevisionId;
    std::optional<qint64> number;
    
    RevisionState state = RevisionState::Working;
    
    QString title;
    QString commitMessage;
    
    QDateTime createdAt;
    QDateTime modifiedAt;
    std::optional<QDateTime> committedAt;
};

#endif // REVISION_H
