POUŽITÍ: corona [-h] [FILTERS] [COMMAND] [LOG [LOG2 [...]]\n\n
    Corona - analyzátor záznamů osob s prokázanou nákazou koronavirem způsobujícím onemocnění COVID-19\n\n
    -h — vypíše nápovědu s krátkým popisem každého příkazu a přepínače\n\n
    FILTERS:\n
     -a DATETIME — after: jsou uvažovány pouze záznamy PO tomto datu (včetně tohoto data). DATETIME je formátu YYYY-MM-DD\n
     -b DATETIME — before: jsou uvažovány pouze záznamy PŘED tímto datem (včetně tohoto data)\n
     -g GENDER — jsou uvažovány pouze záznamy nakažených osob daného pohlaví. GENDER může být M (muži) nebo Z (ženy)\n
     -s u příkazů gender, age, daily, monthly, yearly, countries, districts a regions vypisuje data ne číselně, ale graficky v podobě histogramů\n\n
     COMMAND:\n
      infected — spočítá počet nakažených\n
      merge — sloučí několik souborů se záznamy do jednoho, zachovávající původní pořadí (hlavička bude ve výstupu jen jednou)\n
      gender — vypíše počet nakažených pro jednotlivá pohlaví\n
      age — vypíše statistiku počtu nakažených osob dle věku\n
      daily — vypíše statistiku nakažených osob pro jednotlivé dny\n
      monthly — vypíše statistiku nakažených osob pro jednotlivé měsíce\n
      yearly — vypíše statistiku nakažených osob pro jednotlivé roky\n
      countries — vypíše statistiku nakažených osob pro jednotlivé země nákazy\n
      districts — vypíše statistiku nakažených osob pro jednotlivé okresy\n
      regions — vypíše statistiku nakažených osob pro jednotlivé kraje\n\n"
      
Vstupni data:
  id,datum,vek,pohlavi,kraj_nuts_kod,okres_lau_kod,nakaza_v_zahranici,nakaza_zeme_csu_kod,reportovano_khs
  
  
Supports: csv, gz, bz2 and standart input 
