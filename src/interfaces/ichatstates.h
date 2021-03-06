#ifndef ICHATSTATES_H
#define ICHATSTATES_H

#include <utils/jid.h>

#define CHATSTATES_UUID "{3f924c9c-3539-43f9-8c85-e410b792a946}"

class IChatStates
{
public:
	enum ChatState {
		StateUnknown,
		StateActive,
		StateComposing,
		StatePaused,
		StateInactive,
		StateGone
	};
	enum PermitStatus {
		StatusDefault,
		StatusEnable,
		StatusDisable
	};
public:
	virtual QObject *instance() =0;
	virtual bool isReady(const Jid &AStreamJid) const =0;
	virtual int permitStatus(const Jid &AContactJid) const =0;
	virtual void setPermitStatus(const Jid &AContactJid, int AStatus) =0;
	virtual bool isEnabled(const Jid &AContactJid, const Jid &AStreamJid = Jid::null) const =0;
	virtual bool isSupported(const Jid &AStreamJid, const Jid &AContactJid) const =0;
	virtual int userChatState(const Jid &AStreamJid, const Jid &AContactJid) const =0;
	virtual int selfChatState(const Jid &AStreamJid, const Jid &AContactJid) const =0;
	virtual int userRoomState(const Jid &AStreamJid, const Jid &AUserJid) const =0;
	virtual int selfRoomState(const Jid &AStreamJid, const Jid &ARoomJid) const =0;
protected:
	virtual void permitStatusChanged(const Jid &AContactJid, int AStatus) const =0;
	virtual void supportStatusChanged(const Jid &AStreamJid, const Jid &AContactJid, bool ASupported) const =0;
	virtual void userChatStateChanged(const Jid &AStreamJid, const Jid &AContactJid, int AState) const =0;
	virtual void selfChatStateChanged(const Jid &AStreamJid, const Jid &AContactJid, int AState) const =0;
	virtual void userRoomStateChanged(const Jid &AStreamJid, const Jid &AUserJid, int AState) const =0;
	virtual void selfRoomStateChanged(const Jid &AStreamJid, const Jid &ARoomJid, int AState) const =0;
};

Q_DECLARE_INTERFACE(IChatStates,"Vacuum.Plugin.IChatStates/1.2")

#endif //ICHATSTATES_H
