WITH ConsecutiveVisits AS (
    SELECT
        id,
        visit_date,
        people,
        id - ROW_NUMBER() OVER (ORDER BY visit_date) AS grp
    FROM
        Stadium
    WHERE
        people >= 100
),
GroupedRecords AS (
    SELECT
        grp
    FROM
        ConsecutiveVisits
    GROUP BY
        grp
    HAVING COUNT(*) >= 3
)

SELECT id, visit_date, people
FROM (
        ConsecutiveVisits INNER JOIN GroupedRecords
        ON ConsecutiveVisits.grp = GroupedRecords.grp
    );
