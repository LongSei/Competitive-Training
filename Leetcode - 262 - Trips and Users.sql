With unbannedUsers AS (
    SELECT * 
    FROM Users 
    WHERE banned = "No"
), unbannedTrips AS (
    SELECT *,
        (SUM(CASE 
                WHEN Users.banned = "Yes" THEN 1
                ELSE 0 END)) as cnt
    FROM (
        Trips LEFT JOIN Users 
        ON Users.users_id = Trips.client_id
            OR  Users.users_id = Trips.driver_id)
    GROUP BY id, request_at
)

SELECT request_at as "Day",
        ROUND(SUM(CASE 
            WHEN status IN ("cancelled_by_client", "cancelled_by_driver") THEN 1
            ELSE 0 END) / COUNT(*), 2) as "Cancellation Rate"
FROM unbannedTrips 
WHERE cnt = 0 
    AND request_at BETWEEN "2013-10-01" AND "2013-10-03"
GROUP BY request_at;