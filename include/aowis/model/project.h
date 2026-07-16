#ifndef PROJECT_H
#define PROJECT_H

#include <QDateTime>
#include <QString>
#include <QUuid>

#include <optional>

enum class ProjectState
{
    Active,
    Archived
};

struct Project
{
    QUuid projectId;
    QString name;
    QString description;
    QDateTime createdAt;
    QDateTime modifiedAt;
    std::optional<QDateTime> archivedAt;

    bool isValid() const
    {
        return !this->projectId.isNull();
    }

    ProjectState state() const
    {
        return this->archivedAt.has_value()
            ? ProjectState::Archived
            : ProjectState::Active;
    }
};

#endif // PROJECT_H
