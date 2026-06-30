#if defined _security_system_included
    #endinput
#endif
#define _security_system_included

#include <YSI_Coding/y_hooks>
#include <omp_http>
#include <sscanf2>

#define MAX_PING                250
#define MAX_SCORE               2
#define SECURITY_DELAY          7000
#define SAFE_COUNTRY            "Indonesia"

new PlayerCountry[MAX_PLAYERS][35];
new bool:PlayerChecked[MAX_PLAYERS];
new PlayerScore[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    new ip[24], url[256];
    GetPlayerIp(playerid, ip, sizeof(ip));

    format(url, sizeof(url), "http://ip-api.com/csv/%s?fields=country,proxy,hosting", ip);
    HTTP(playerid, HTTP_GET, url, "", "SECURITY_HTTP");

    PlayerChecked[playerid] = false;
    PlayerScore[playerid] = 0;

    SetTimerEx("SECURITY_Check", SECURITY_DELAY, false, "i", playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

forward SECURITY_HTTP(playerid, response_code, data[]);
public SECURITY_HTTP(playerid, response_code, data[])
{
    if(response_code != 200) return 1;

    new country[35], proxy[6], hosting[6];
    sscanf(data, "p<,>s[35]s[6]s[6]", country, proxy, hosting);

    if(strlen(country) > 0 && country[strlen(country)-1] == '\n')
        country[strlen(country)-1] = '\0';

    format(PlayerCountry[playerid], sizeof(PlayerCountry[]), "%s", country);

    if(!strcmp(proxy, "true", true)) PlayerScore[playerid] += 2;
    if(!strcmp(hosting, "true", true)) PlayerScore[playerid] += 1;
    if(strcmp(country, SAFE_COUNTRY, true) != 0) PlayerScore[playerid] += 1;

    PlayerChecked[playerid] = true;

    printf("[SECURITY] ID:%d | Country:%s | Score:%d", playerid, country, PlayerScore[playerid]);
    return 1;
}

forward SECURITY_Check(playerid);
public SECURITY_Check(playerid)
{
    if(!IsPlayerConnected(playerid)) return 1;

    if(!PlayerChecked[playerid])
    {
        printf("[SECURITY] Player %d skipped (API timeout or failure)", playerid);
        return 1;
    }

    new ping = GetPlayerPing(playerid);
    if(ping > MAX_PING) PlayerScore[playerid] += 1;

    if(PlayerScore[playerid] >= MAX_SCORE)
    {
        SendClientMessage(playerid, -1, "Connection blocked (VPN/Proxy/High Ping).");
        Kick(playerid);
    }
    else
    {
        printf("[SECURITY] Player %d allowed (Score:%d | Ping:%d)",
            playerid, PlayerScore[playerid], ping);
    }

    return 1;
}
