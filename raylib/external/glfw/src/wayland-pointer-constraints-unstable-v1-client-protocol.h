/* Generated by wayland-scanner 1.12.0 */

#ifndef POINTER_CONSTRAINTS_UNSTABLE_V1_CLIENT_PROTOCOL_H
#define POINTER_CONSTRAINTS_UNSTABLE_V1_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_pointer_constraints_unstable_v1 The pointer_constraints_unstable_v1 protocol
 * protocol for constraining pointer motions
 *
 * @section page_desc_pointer_constraints_unstable_v1 Description
 *
 * This protocol specifies a set of interfaces used for adding constraints to
 * the motion of a pointer. Possible constraints include confining pointer
 * motions to a given region, or locking it to its current position.
 *
 * In order to constrain the pointer, a client must first bind the global
 * interface "wp_pointer_constraints" which, if a compositor supports pointer
 * constraints, is exposed by the registry. Using the bound global object, the
 * client uses the request that corresponds to the type of constraint it wants
 * to make. See wp_pointer_constraints for more details.
 *
 * Warning! The protocol described in this file is experimental and backward
 * incompatible changes may be made. Backward compatible changes may be added
 * together with the corresponding interface version bump. Backward
 * incompatible changes are done by bumping the version number in the protocol
 * and interface names and resetting the interface version. Once the protocol
 * is to be declared stable, the 'z' prefix and the version number in the
 * protocol and interface names are removed and the interface version number is
 * reset.
 *
 * @section page_ifaces_pointer_constraints_unstable_v1 Interfaces
 * - @subpage page_iface_zwp_pointer_constraints_v1 - constrain the movement of a pointer
 * - @subpage page_iface_zwp_locked_pointer_v1 - receive relative pointer motion events
 * - @subpage page_iface_zwp_confined_pointer_v1 - confined pointer object
 * @section page_copyright_pointer_constraints_unstable_v1 Copyright
 * <pre>
 *
 * Copyright © 2014      Jonas Ådahl
 * Copyright © 2015      Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct wl_pointer;
struct wl_region;
struct wl_surface;
struct zwp_confined_pointer_v1;
struct zwp_locked_pointer_v1;
struct zwp_pointer_constraints_v1;

/**
 * @page page_iface_zwp_pointer_constraints_v1 zwp_pointer_constraints_v1
 * @section page_iface_zwp_pointer_constraints_v1_desc Description
 *
 * The global interface exposing pointer constraining functionality. It
 * exposes two requests: lock_pointer for locking the pointer to its
 * position, and confine_pointer for locking the pointer to a region.
 *
 * The lock_pointer and confine_pointer requests create the objects
 * wp_locked_pointer and wp_confined_pointer respectively, and the client can
 * use these objects to interact with the lock.
 *
 * For any surface, only one lock or confinement may be active across all
 * wl_pointer objects of the same seat. If a lock or confinement is requested
 * when another lock or confinement is active or requested on the same surface
 * and with any of the wl_pointer objects of the same seat, an
 * 'already_constrained' error will be raised.
 * @section page_iface_zwp_pointer_constraints_v1_api API
 * See @ref iface_zwp_pointer_constraints_v1.
 */
/**
 * @defgroup iface_zwp_pointer_constraints_v1 The zwp_pointer_constraints_v1 interface
 *
 * The global interface exposing pointer constraining functionality. It
 * exposes two requests: lock_pointer for locking the pointer to its
 * position, and confine_pointer for locking the pointer to a region.
 *
 * The lock_pointer and confine_pointer requests create the objects
 * wp_locked_pointer and wp_confined_pointer respectively, and the client can
 * use these objects to interact with the lock.
 *
 * For any surface, only one lock or confinement may be active across all
 * wl_pointer objects of the same seat. If a lock or confinement is requested
 * when another lock or confinement is active or requested on the same surface
 * and with any of the wl_pointer objects of the same seat, an
 * 'already_constrained' error will be raised.
 */
extern const struct wl_interface zwp_pointer_constraints_v1_interface;
/**
 * @page page_iface_zwp_locked_pointer_v1 zwp_locked_pointer_v1
 * @section page_iface_zwp_locked_pointer_v1_desc Description
 *
 * The wp_locked_pointer interface represents a locked pointer state.
 *
 * While the lock of this object is active, the wl_pointer objects of the
 * associated seat will not emit any wl_pointer.motion events.
 *
 * This object will send the event 'locked' when the lock is activated.
 * Whenever the lock is activated, it is guaranteed that the locked surface
 * will already have received pointer focus and that the pointer will be
 * within the region passed to the request creating this object.
 *
 * To unlock the pointer, send the destroy request. This will also destroy
 * the wp_locked_pointer object.
 *
 * If the compositor decides to unlock the pointer the unlocked event is
 * sent. See wp_locked_pointer.unlock for details.
 *
 * When unlocking, the compositor may warp the cursor position to the set
 * cursor position hint. If it does, it will not result in any relative
 * motion events emitted via wp_relative_pointer.
 *
 * If the surface the lock was requested on is destroyed and the lock is not
 * yet activated, the wp_locked_pointer object is now defunct and must be
 * destroyed.
 * @section page_iface_zwp_locked_pointer_v1_api API
 * See @ref iface_zwp_locked_pointer_v1.
 */
/**
 * @defgroup iface_zwp_locked_pointer_v1 The zwp_locked_pointer_v1 interface
 *
 * The wp_locked_pointer interface represents a locked pointer state.
 *
 * While the lock of this object is active, the wl_pointer objects of the
 * associated seat will not emit any wl_pointer.motion events.
 *
 * This object will send the event 'locked' when the lock is activated.
 * Whenever the lock is activated, it is guaranteed that the locked surface
 * will already have received pointer focus and that the pointer will be
 * within the region passed to the request creating this object.
 *
 * To unlock the pointer, send the destroy request. This will also destroy
 * the wp_locked_pointer object.
 *
 * If the compositor decides to unlock the pointer the unlocked event is
 * sent. See wp_locked_pointer.unlock for details.
 *
 * When unlocking, the compositor may warp the cursor position to the set
 * cursor position hint. If it does, it will not result in any relative
 * motion events emitted via wp_relative_pointer.
 *
 * If the surface the lock was requested on is destroyed and the lock is not
 * yet activated, the wp_locked_pointer object is now defunct and must be
 * destroyed.
 */
extern const struct wl_interface zwp_locked_pointer_v1_interface;
/**
 * @page page_iface_zwp_confined_pointer_v1 zwp_confined_pointer_v1
 * @section page_iface_zwp_confined_pointer_v1_desc Description
 *
 * The wp_confined_pointer interface represents a confined pointer state.
 *
 * This object will send the event 'confined' when the confinement is
 * activated. Whenever the confinement is activated, it is guaranteed that
 * the surface the pointer is confined to will already have received pointer
 * focus and that the pointer will be within the region passed to the request
 * creating this object. It is up to the compositor to decide whether this
 * requires some user interaction and if the pointer will warp to within the
 * passed region if outside.
 *
 * To unconfine the pointer, send the destroy request. This will also destroy
 * the wp_confined_pointer object.
 *
 * If the compositor decides to unconfine the pointer the unconfined event is
 * sent. The wp_confined_pointer object is at this point defunct and should
 * be destroyed.
 * @section page_iface_zwp_confined_pointer_v1_api API
 * See @ref iface_zwp_confined_pointer_v1.
 */
/**
 * @defgroup iface_zwp_confined_pointer_v1 The zwp_confined_pointer_v1 interface
 *
 * The wp_confined_pointer interface represents a confined pointer state.
 *
 * This object will send the event 'confined' when the confinement is
 * activated. Whenever the confinement is activated, it is guaranteed that
 * the surface the pointer is confined to will already have received pointer
 * focus and that the pointer will be within the region passed to the request
 * creating this object. It is up to the compositor to decide whether this
 * requires some user interaction and if the pointer will warp to within the
 * passed region if outside.
 *
 * To unconfine the pointer, send the destroy request. This will also destroy
 * the wp_confined_pointer object.
 *
 * If the compositor decides to unconfine the pointer the unconfined event is
 * sent. The wp_confined_pointer object is at this point defunct and should
 * be destroyed.
 */
extern const struct wl_interface zwp_confined_pointer_v1_interface;

#ifndef ZWP_POINTER_CONSTRAINTS_V1_ERROR_ENUM
#define ZWP_POINTER_CONSTRAINTS_V1_ERROR_ENUM
/**
 * @ingroup iface_zwp_pointer_constraints_v1
 * wp_pointer_constraints error values
 *
 * These errors can be emitted in response to wp_pointer_constraints
 * requests.
 */
enum zwp_pointer_constraints_v1_error {
	/**
	 * pointer constraint already requested on that surface
	 */
	ZWP_POINTER_CONSTRAINTS_V1_ERROR_ALREADY_CONSTRAINED = 1,
};
#endif /* ZWP_POINTER_CONSTRAINTS_V1_ERROR_ENUM */

#ifndef ZWP_POINTER_CONSTRAINTS_V1_LIFETIME_ENUM
#define ZWP_POINTER_CONSTRAINTS_V1_LIFETIME_ENUM
/**
 * @ingroup iface_zwp_pointer_constraints_v1
 * the pointer constraint may reactivate
 *
 * A persistent pointer constraint may again reactivate once it has
 * been deactivated. See the corresponding deactivation event
 * (wp_locked_pointer.unlocked and wp_confined_pointer.unconfined) for
 * details.
 */
enum zwp_pointer_constraints_v1_lifetime {
	ZWP_POINTER_CONSTRAINTS_V1_LIFETIME_ONESHOT = 1,
	ZWP_POINTER_CONSTRAINTS_V1_LIFETIME_PERSISTENT = 2,
};
#endif /* ZWP_POINTER_CONSTRAINTS_V1_LIFETIME_ENUM */

#define ZWP_POINTER_CONSTRAINTS_V1_DESTROY 0
#define ZWP_POINTER_CONSTRAINTS_V1_LOCK_POINTER 1
#define ZWP_POINTER_CONSTRAINTS_V1_CONFINE_POINTER 2


/**
 * @ingroup iface_zwp_pointer_constraints_v1
 */
#define ZWP_POINTER_CONSTRAINTS_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_pointer_constraints_v1
 */
#define ZWP_POINTER_CONSTRAINTS_V1_LOCK_POINTER_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_pointer_constraints_v1
 */
#define ZWP_POINTER_CONSTRAINTS_V1_CONFINE_POINTER_SINCE_VERSION 1

/** @ingroup iface_zwp_pointer_constraints_v1 */
static inline void
zwp_pointer_constraints_v1_set_user_data(struct zwp_pointer_constraints_v1 *zwp_pointer_constraints_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwp_pointer_constraints_v1, user_data);
}

/** @ingroup iface_zwp_pointer_constraints_v1 */
static inline void *
zwp_pointer_constraints_v1_get_user_data(struct zwp_pointer_constraints_v1 *zwp_pointer_constraints_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwp_pointer_constraints_v1);
}

static inline uint32_t
zwp_pointer_constraints_v1_get_version(struct zwp_pointer_constraints_v1 *zwp_pointer_constraints_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwp_pointer_constraints_v1);
}

/**
 * @ingroup iface_zwp_pointer_constraints_v1
 *
 * Used by the client to notify the server that it will no longer use this
 * pointer constraints object.
 */
static inline void
zwp_pointer_constraints_v1_destroy(struct zwp_pointer_constraints_v1 *zwp_pointer_constraints_v1)
{
	wl_proxy_marshal((struct wl_proxy *) zwp_pointer_constraints_v1,
			 ZWP_POINTER_CONSTRAINTS_V1_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) zwp_pointer_constraints_v1);
}

/**
 * @ingroup iface_zwp_pointer_constraints_v1
 *
 * The lock_pointer request lets the client request to disable movements of
 * the virtual pointer (i.e. the cursor), effectively locking the pointer
 * to a position. This request may not take effect immediately; in the
 * future, when the compositor deems implementation-specific constraints
 * are satisfied, the pointer lock will be activated and the compositor
 * sends a locked event.
 *
 * The protocol provides no guarantee that the constraints are ever
 * satisfied, and does not require the compositor to send an error if the
 * constraints cannot ever be satisfied. It is thus possible to request a
 * lock that will never activate.
 *
 * There may not be another pointer constraint of any kind requested or
 * active on the surface for any of the wl_pointer objects of the seat of
 * the passed pointer when requesting a lock. If there is, an error will be
 * raised. See general pointer lock documentation for more details.
 *
 * The intersection of the region passed with this request and the input
 * region of the surface is used to determine where the pointer must be
 * in order for the lock to activate. It is up to the compositor whether to
 * warp the pointer or require some kind of user interaction for the lock
 * to activate. If the region is null the surface input region is used.
 *
 * A surface may receive pointer focus without the lock being activated.
 *
 * The request creates a new object wp_locked_pointer which is used to
 * interact with the lock as well as receive updates about its state. See
 * the the description of wp_locked_pointer for further information.
 *
 * Note that while a pointer is locked, the wl_pointer objects of the
 * corresponding seat will not emit any wl_pointer.motion events, but
 * relative motion events will still be emitted via wp_relative_pointer
 * objects of the same seat. wl_pointer.axis and wl_pointer.button events
 * are unaffected.
 */
static inline struct zwp_locked_pointer_v1 *
zwp_pointer_constraints_v1_lock_pointer(struct zwp_pointer_constraints_v1 *zwp_pointer_constraints_v1, struct wl_surface *surface, struct wl_pointer *pointer, struct wl_region *region, uint32_t lifetime)
{
	struct wl_proxy *id;

	id = wl_proxy_marshal_constructor((struct wl_proxy *) zwp_pointer_constraints_v1,
			 ZWP_POINTER_CONSTRAINTS_V1_LOCK_POINTER, &zwp_locked_pointer_v1_interface, NULL, surface, pointer, region, lifetime);

	return (struct zwp_locked_pointer_v1 *) id;
}

/**
 * @ingroup iface_zwp_pointer_constraints_v1
 *
 * The confine_pointer request lets the client request to confine the
 * pointer cursor to a given region. This request may not take effect
 * immediately; in the future, when the compositor deems implementation-
 * specific constraints are satisfied, the pointer confinement will be
 * activated and the compositor sends a confined event.
 *
 * The intersection of the region passed with this request and the input
 * region of the surface is used to determine where the pointer must be
 * in order for the confinement to activate. It is up to the compositor
 * whether to warp the pointer or require some kind of user interaction for
 * the confinement to activate. If the region is null the surface input
 * region is used.
 *
 * The request will create a new object wp_confined_pointer which is used
 * to interact with the confinement as well as receive updates about its
 * state. See the the description of wp_confined_pointer for further
 * information.
 */
static inline struct zwp_confined_pointer_v1 *
zwp_pointer_constraints_v1_confine_pointer(struct zwp_pointer_constraints_v1 *zwp_pointer_constraints_v1, struct wl_surface *surface, struct wl_pointer *pointer, struct wl_region *region, uint32_t lifetime)
{
	struct wl_proxy *id;

	id = wl_proxy_marshal_constructor((struct wl_proxy *) zwp_pointer_constraints_v1,
			 ZWP_POINTER_CONSTRAINTS_V1_CONFINE_POINTER, &zwp_confined_pointer_v1_interface, NULL, surface, pointer, region, lifetime);

	return (struct zwp_confined_pointer_v1 *) id;
}

/**
 * @ingroup iface_zwp_locked_pointer_v1
 * @struct zwp_locked_pointer_v1_listener
 */
struct zwp_locked_pointer_v1_listener {
	/**
	 * lock activation event
	 *
	 * Notification that the pointer lock of the seat's pointer is
	 * activated.
	 */
	void (*locked)(void *data,
		       struct zwp_locked_pointer_v1 *zwp_locked_pointer_v1);
	/**
	 * lock deactivation event
	 *
	 * Notification that the pointer lock of the seat's pointer is no
	 * longer active. If this is a oneshot pointer lock (see
	 * wp_pointer_constraints.lifetime) this object is now defunct and
	 * should be destroyed. If this is a persistent pointer lock (see
	 * wp_pointer_constraints.lifetime) this pointer lock may again
	 * reactivate in the future.
	 */
	void (*unlocked)(void *data,
			 struct zwp_locked_pointer_v1 *zwp_locked_pointer_v1);
};

/**
 * @ingroup zwp_locked_pointer_v1_iface
 */
static inline int
zwp_locked_pointer_v1_add_listener(struct zwp_locked_pointer_v1 *zwp_locked_pointer_v1,
				   const struct zwp_locked_pointer_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwp_locked_pointer_v1,
				     (void (**)(void)) listener, data);
}

#define ZWP_LOCKED_POINTER_V1_DESTROY 0
#define ZWP_LOCKED_POINTER_V1_SET_CURSOR_POSITION_HINT 1
#define ZWP_LOCKED_POINTER_V1_SET_REGION 2

/**
 * @ingroup iface_zwp_locked_pointer_v1
 */
#define ZWP_LOCKED_POINTER_V1_LOCKED_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_locked_pointer_v1
 */
#define ZWP_LOCKED_POINTER_V1_UNLOCKED_SINCE_VERSION 1

/**
 * @ingroup iface_zwp_locked_pointer_v1
 */
#define ZWP_LOCKED_POINTER_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_locked_pointer_v1
 */
#define ZWP_LOCKED_POINTER_V1_SET_CURSOR_POSITION_HINT_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_locked_pointer_v1
 */
#define ZWP_LOCKED_POINTER_V1_SET_REGION_SINCE_VERSION 1

/** @ingroup iface_zwp_locked_pointer_v1 */
static inline void
zwp_locked_pointer_v1_set_user_data(struct zwp_locked_pointer_v1 *zwp_locked_pointer_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwp_locked_pointer_v1, user_data);
}

/** @ingroup iface_zwp_locked_pointer_v1 */
static inline void *
zwp_locked_pointer_v1_get_user_data(struct zwp_locked_pointer_v1 *zwp_locked_pointer_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwp_locked_pointer_v1);
}

static inline uint32_t
zwp_locked_pointer_v1_get_version(struct zwp_locked_pointer_v1 *zwp_locked_pointer_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwp_locked_pointer_v1);
}

/**
 * @ingroup iface_zwp_locked_pointer_v1
 *
 * Destroy the locked pointer object. If applicable, the compositor will
 * unlock the pointer.
 */
static inline void
zwp_locked_pointer_v1_destroy(struct zwp_locked_pointer_v1 *zwp_locked_pointer_v1)
{
	wl_proxy_marshal((struct wl_proxy *) zwp_locked_pointer_v1,
			 ZWP_LOCKED_POINTER_V1_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) zwp_locked_pointer_v1);
}

/**
 * @ingroup iface_zwp_locked_pointer_v1
 *
 * Set the cursor position hint relative to the top left corner of the
 * surface.
 *
 * If the client is drawing its own cursor, it should update the position
 * hint to the position of its own cursor. A compositor may use this
 * information to warp the pointer upon unlock in order to avoid pointer
 * jumps.
 *
 * The cursor position hint is double buffered. The new hint will only take
 * effect when the associated surface gets it pending state applied. See
 * wl_surface.commit for details.
 */
static inline void
zwp_locked_pointer_v1_set_cursor_position_hint(struct zwp_locked_pointer_v1 *zwp_locked_pointer_v1, wl_fixed_t surface_x, wl_fixed_t surface_y)
{
	wl_proxy_marshal((struct wl_proxy *) zwp_locked_pointer_v1,
			 ZWP_LOCKED_POINTER_V1_SET_CURSOR_POSITION_HINT, surface_x, surface_y);
}

/**
 * @ingroup iface_zwp_locked_pointer_v1
 *
 * Set a new region used to lock the pointer.
 *
 * The new lock region is double-buffered. The new lock region will
 * only take effect when the associated surface gets its pending state
 * applied. See wl_surface.commit for details.
 *
 * For details about the lock region, see wp_locked_pointer.
 */
static inline void
zwp_locked_pointer_v1_set_region(struct zwp_locked_pointer_v1 *zwp_locked_pointer_v1, struct wl_region *region)
{
	wl_proxy_marshal((struct wl_proxy *) zwp_locked_pointer_v1,
			 ZWP_LOCKED_POINTER_V1_SET_REGION, region);
}

/**
 * @ingroup iface_zwp_confined_pointer_v1
 * @struct zwp_confined_pointer_v1_listener
 */
struct zwp_confined_pointer_v1_listener {
	/**
	 * pointer confined
	 *
	 * Notification that the pointer confinement of the seat's
	 * pointer is activated.
	 */
	void (*confined)(void *data,
			 struct zwp_confined_pointer_v1 *zwp_confined_pointer_v1);
	/**
	 * pointer unconfined
	 *
	 * Notification that the pointer confinement of the seat's
	 * pointer is no longer active. If this is a oneshot pointer
	 * confinement (see wp_pointer_constraints.lifetime) this object is
	 * now defunct and should be destroyed. If this is a persistent
	 * pointer confinement (see wp_pointer_constraints.lifetime) this
	 * pointer confinement may again reactivate in the future.
	 */
	void (*unconfined)(void *data,
			   struct zwp_confined_pointer_v1 *zwp_confined_pointer_v1);
};

/**
 * @ingroup zwp_confined_pointer_v1_iface
 */
static inline int
zwp_confined_pointer_v1_add_listener(struct zwp_confined_pointer_v1 *zwp_confined_pointer_v1,
				     const struct zwp_confined_pointer_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwp_confined_pointer_v1,
				     (void (**)(void)) listener, data);
}

#define ZWP_CONFINED_POINTER_V1_DESTROY 0
#define ZWP_CONFINED_POINTER_V1_SET_REGION 1

/**
 * @ingroup iface_zwp_confined_pointer_v1
 */
#define ZWP_CONFINED_POINTER_V1_CONFINED_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_confined_pointer_v1
 */
#define ZWP_CONFINED_POINTER_V1_UNCONFINED_SINCE_VERSION 1

/**
 * @ingroup iface_zwp_confined_pointer_v1
 */
#define ZWP_CONFINED_POINTER_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zwp_confined_pointer_v1
 */
#define ZWP_CONFINED_POINTER_V1_SET_REGION_SINCE_VERSION 1

/** @ingroup iface_zwp_confined_pointer_v1 */
static inline void
zwp_confined_pointer_v1_set_user_data(struct zwp_confined_pointer_v1 *zwp_confined_pointer_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwp_confined_pointer_v1, user_data);
}

/** @ingroup iface_zwp_confined_pointer_v1 */
static inline void *
zwp_confined_pointer_v1_get_user_data(struct zwp_confined_pointer_v1 *zwp_confined_pointer_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwp_confined_pointer_v1);
}

static inline uint32_t
zwp_confined_pointer_v1_get_version(struct zwp_confined_pointer_v1 *zwp_confined_pointer_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwp_confined_pointer_v1);
}

/**
 * @ingroup iface_zwp_confined_pointer_v1
 *
 * Destroy the confined pointer object. If applicable, the compositor will
 * unconfine the pointer.
 */
static inline void
zwp_confined_pointer_v1_destroy(struct zwp_confined_pointer_v1 *zwp_confined_pointer_v1)
{
	wl_proxy_marshal((struct wl_proxy *) zwp_confined_pointer_v1,
			 ZWP_CONFINED_POINTER_V1_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) zwp_confined_pointer_v1);
}

/**
 * @ingroup iface_zwp_confined_pointer_v1
 *
 * Set a new region used to confine the pointer.
 *
 * The new confine region is double-buffered. The new confine region will
 * only take effect when the associated surface gets its pending state
 * applied. See wl_surface.commit for details.
 *
 * If the confinement is active when the new confinement region is applied
 * and the pointer ends up outside of newly applied region, the pointer may
 * warped to a position within the new confinement region. If warped, a
 * wl_pointer.motion event will be emitted, but no
 * wp_relative_pointer.relative_motion event.
 *
 * The compositor may also, instead of using the new region, unconfine the
 * pointer.
 *
 * For details about the confine region, see wp_confined_pointer.
 */
static inline void
zwp_confined_pointer_v1_set_region(struct zwp_confined_pointer_v1 *zwp_confined_pointer_v1, struct wl_region *region)
{
	wl_proxy_marshal((struct wl_proxy *) zwp_confined_pointer_v1,
			 ZWP_CONFINED_POINTER_V1_SET_REGION, region);
}

#ifdef  __cplusplus
}
#endif

#endif
