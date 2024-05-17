library(DBI)
library(RMySQL)


# Set connection parameters
con <- dbConnect(RMySQL::MySQL(),
                 dbname = "tweater",
                 host = "courses.csrrinzqubik.us-east-1.rds.amazonaws.com",
                 port = 3306,
                 user = "student",
                 password = Sys.getenv("passwd"))

# create a vecor to store table names
tables = dbListTables(con)

# Display all tables int he database
str(tables)

# Import into R environment the users table
users = dbReadTable(con, "users")

# Select * from users;
print(users)

# Query
user_names <- dbGetQuery(
    con,
    "SELECT id, name FROM users;"
)

# inner join
tweats <- dbReadTable(con, "tweats")
comments <- dbReadTable(con, "comments")

dbGetQuery(
    con,
    "SELECT
        users.name AS user_post,
        tweats.user_id,
        tweats.post,
        comments.user_id AS user_id_comment,
        comments.message AS comment
    FROM users
    INNER JOIN tweats ON users.id = tweats.user_id
    INNER JOIN comments ON tweats.id = comments.tweat_id;"
)

# Disconnect from the database
dbDisconnect(con)
