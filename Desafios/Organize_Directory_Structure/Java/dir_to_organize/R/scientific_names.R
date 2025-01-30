nome_cientifico <- c("Mezilaurus itauba", "Mezilaurus sp", "Cedrela",
                     "Pouteria", "Pouteria spartiana", "Pouteria paraensis",
                     "Apuleia spp.")


grep("\\w+\\s(sp$|spp$?|spp.$?)", nome_cientifico, value = TRUE)

gsub("(\\w+)\\sspp$|\\ssp$||\\ssp.$|\\sspp.$", "\\1", nome_cientifico)


# Get only botanical genre
grepl("^\\w+$", nome_cientifico)

gsub("(^\\w+)\\s\\w+", "\\1", nome_cientifico)
