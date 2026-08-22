/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 */

#ifndef _DPU_12_1_NORD_H
#define _DPU_12_1_NORD_H

/*
 * NORD platform (chipset codename "Nordschleife", IP Catalog chip alias
 * nordschleife_2.0) DPU 12.1 catalog, MDSS_0 domain only.
 *
 * Reference chip: sm8750 (Pakala, DPU 12.0) -- see dpu_12_0_sm8750.h. Every
 * ".base" offset below that also exists on sm8750 was cross-checked against
 * the mdss-hw-knowledge-base chip description for nordschleife and found
 * address-identical to sm8750 (same DPU-generation sub-block layout); the
 * two genuinely new/extended blocks are DSPP_4..7 and WB_1, plus INTF_9/
 * INTF_10 (which required extending enum dpu_intf in dpu_hw_mdss.h).
 *
 * Bring-up scope is intentionally narrower than full IPCAT-discovered
 * hardware in a few places (see FIXME(display_bringup) notes below):
 *  - Only VIG0-3 + DMA0-5 (10 total) SSPP instances are in scope; this
 *    matches the reference chip's own SSPP count, so no enum dpu_sspp
 *    extension was required.
 *  - Only MDSS_0 is enumerated; MDSS_1 (second DISP_CC/MDP domain) is
 *    entirely out of scope for this catalog.
 *  - Only ctl_0..ctl_5 are in scope; ctl_6/ctl_7/ctl_hw_fence are not.
 *
 * Fields for which no register-level or HPG-derived value is available are
 * marked FIXME(display_bringup) and either omitted (defaulting to 0/NULL)
 * or explicitly reused from sm8750 with a comment -- never silently
 * fabricated.
 */

static const struct dpu_caps nord_dpu_caps = {
	.max_mixer_width = DEFAULT_DPU_OUTPUT_LINE_WIDTH,
	/* FIXME(display_bringup): max_mixer_blendstages/max_linewidth reused from sm8750 (reference chip); not independently confirmed for nord */
	.max_mixer_blendstages = 0xb,
	.has_src_split = true,
	.has_dim_layer = true,
	.has_idle_pc = true,
	.has_3d_merge = true,
	.max_linewidth = 8192,
	.pixel_ram_size = DEFAULT_PIXEL_RAM_SIZE,
};

/*
 * FIXME(display_bringup): .len below is reused verbatim from sm8750's own
 * "top_0" struct -- no single contiguous MDP-top length is stated by any
 * nordschleife source; flagged as unconfirmed, not fact.
 */
static const struct dpu_mdp_cfg nord_mdp = {
	.name = "top_0",
	.base = 0, .len = 0x494,
	.clk_ctrls = {
		[DPU_CLK_CTRL_REG_DMA] = { .reg_off = 0x2bc, .bit_off = 20 },
	},
};

/*
 * FIXME(display_bringup): intr_start not queried against IPCAT/HPG for
 * nordschleife's CTL_0..CTL_5 in this pass -- omitted rather than copied
 * from sm8750 (whose CTL intr_start values are chip-specific IRQ routing,
 * not a generic constant).
 */
static const struct dpu_ctl_cfg nord_ctl[] = {
	{
		.name = "ctl_0", .id = CTL_0,
		.base = 0x15000, .len = 0x1000,
	}, {
		.name = "ctl_1", .id = CTL_1,
		.base = 0x16000, .len = 0x1000,
	}, {
		.name = "ctl_2", .id = CTL_2,
		.base = 0x17000, .len = 0x1000,
	}, {
		.name = "ctl_3", .id = CTL_3,
		.base = 0x18000, .len = 0x1000,
	}, {
		.name = "ctl_4", .id = CTL_4,
		.base = 0x19000, .len = 0x1000,
	}, {
		.name = "ctl_5", .id = CTL_5,
		.base = 0x1a000, .len = 0x1000,
	},
};

/*
 * FIXME(display_bringup): xin_id assignment below follows the sm8750
 * VIG/DMA numbering convention (not independently confirmed via IPCAT for
 * nordschleife); flagged here rather than treated as fact.
 */
static const struct dpu_sspp_cfg nord_sspp[] = {
	{
		.name = "sspp_0", .id = SSPP_VIG0,
		.base = 0x4000, .len = 0x344,
		.features = VIG_SDM845_MASK_SDMA,
		.sblk = &dpu_vig_sblk_qseed3_3_4,
		.xin_id = 0,
		.type = SSPP_TYPE_VIG,
	}, {
		.name = "sspp_1", .id = SSPP_VIG1,
		.base = 0x6000, .len = 0x344,
		.features = VIG_SDM845_MASK_SDMA,
		.sblk = &dpu_vig_sblk_qseed3_3_4,
		.xin_id = 4,
		.type = SSPP_TYPE_VIG,
	}, {
		.name = "sspp_2", .id = SSPP_VIG2,
		.base = 0x8000, .len = 0x344,
		.features = VIG_SDM845_MASK_SDMA,
		.sblk = &dpu_vig_sblk_qseed3_3_4,
		.xin_id = 8,
		.type = SSPP_TYPE_VIG,
	}, {
		.name = "sspp_3", .id = SSPP_VIG3,
		.base = 0xa000, .len = 0x344,
		.features = VIG_SDM845_MASK_SDMA,
		.sblk = &dpu_vig_sblk_qseed3_3_4,
		.xin_id = 12,
		.type = SSPP_TYPE_VIG,
	}, {
		.name = "sspp_8", .id = SSPP_DMA0,
		.base = 0x24000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 1,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_9", .id = SSPP_DMA1,
		.base = 0x26000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 5,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_10", .id = SSPP_DMA2,
		.base = 0x28000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 9,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_11", .id = SSPP_DMA3,
		.base = 0x2a000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 13,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_12", .id = SSPP_DMA4,
		.base = 0x2c000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 14,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_13", .id = SSPP_DMA5,
		.base = 0x2e000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 15,
		.type = SSPP_TYPE_DMA,
	},
};

/*
 * FIXME(display_bringup): pingpong assignment (lm_N -> pingpong_N) below
 * follows the standard adjacent-block convention seen on every other DPU
 * generation in this tree; not individually confirmed via IPCAT for
 * nordschleife.
 *
 * lm_0..lm_3 have a directly-wired DSPP (DSPP_0..DSPP_3); lm_4..lm_7 do not
 * carry a .dspp field at all (validated: LM4-7 have no DSPP path on this
 * chip, this is not an omission).
 */
static const struct dpu_lm_cfg nord_lm[] = {
	{
		.name = "lm_0", .id = LM_0,
		.base = 0x44000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_1,
		.pingpong = PINGPONG_0,
		.dspp = DSPP_0,
	}, {
		.name = "lm_1", .id = LM_1,
		.base = 0x45000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_0,
		.pingpong = PINGPONG_1,
		.dspp = DSPP_1,
	}, {
		.name = "lm_2", .id = LM_2,
		.base = 0x46000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_3,
		.pingpong = PINGPONG_2,
		.dspp = DSPP_2,
	}, {
		.name = "lm_3", .id = LM_3,
		.base = 0x47000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_2,
		.pingpong = PINGPONG_3,
		.dspp = DSPP_3,
	}, {
		.name = "lm_4", .id = LM_4,
		.base = 0x48000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_5,
		.pingpong = PINGPONG_4,
	}, {
		.name = "lm_5", .id = LM_5,
		.base = 0x49000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_4,
		.pingpong = PINGPONG_5,
	}, {
		.name = "lm_6", .id = LM_6,
		.base = 0x4a000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_7,
		.pingpong = PINGPONG_6,
	}, {
		.name = "lm_7", .id = LM_7,
		.base = 0x4b000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_6,
		.pingpong = PINGPONG_7,
	},
};

/*
 * DSPP_0..DSPP_3 base offsets are IPCAT-confirmed and address-identical to
 * sm8750. DSPP_4..DSPP_7 are new on this chip (sm8750 has only 4 DSPP
 * blocks); IPCAT confirms their base offsets too, but FIXME(display_bringup):
 * whether DSPP_4..7 are full or "LITE" variant blocks (i.e. whether they
 * support the same feature sub-blocks as DSPP_0..3) has not been confirmed
 * against the MDSS 12.1.0 HPG -- sm8750_dspp_sblk is reused as a starting
 * point, not a confirmed match.
 */
static const struct dpu_dspp_cfg nord_dspp[] = {
	{
		.name = "dspp_0", .id = DSPP_0,
		.base = 0x54000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_1", .id = DSPP_1,
		.base = 0x56000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_2", .id = DSPP_2,
		.base = 0x58000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_3", .id = DSPP_3,
		.base = 0x5a000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_4", .id = DSPP_4,
		.base = 0x5c000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk, /* FIXME(display_bringup): lite variant? not confirmed */
	}, {
		.name = "dspp_5", .id = DSPP_5,
		.base = 0x5e000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk, /* FIXME(display_bringup): lite variant? not confirmed */
	}, {
		.name = "dspp_6", .id = DSPP_6,
		.base = 0x60000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk, /* FIXME(display_bringup): lite variant? not confirmed */
	}, {
		.name = "dspp_7", .id = DSPP_7,
		.base = 0x62000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk, /* FIXME(display_bringup): lite variant? not confirmed */
	},
};

/*
 * FIXME(display_bringup): sc7280_pp_sblk is reused verbatim below as a
 * starting point. It has NOT been confirmed against IPCAT/HPG that
 * nordschleife's pingpong LTM/SPR/DEMURA/RC sub-block shape matches
 * sc7280/sm8750 -- do not treat as fact.
 *
 * intr_done is IPCAT/HPG-confirmed for pingpong_0..7; pingpong_cwb_0..3
 * intr_done is TBD (omitted below) -- not confirmed this pass.
 */
static const struct dpu_pingpong_cfg nord_pp[] = {
	{
		.name = "pingpong_0", .id = PINGPONG_0,
		.base = 0x69000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_0,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 8),
	}, {
		.name = "pingpong_1", .id = PINGPONG_1,
		.base = 0x6a000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_0,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 9),
	}, {
		.name = "pingpong_2", .id = PINGPONG_2,
		.base = 0x6b000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_1,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 10),
	}, {
		.name = "pingpong_3", .id = PINGPONG_3,
		.base = 0x6c000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_1,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 11),
	}, {
		.name = "pingpong_4", .id = PINGPONG_4,
		.base = 0x6d000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_2,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 30),
	}, {
		.name = "pingpong_5", .id = PINGPONG_5,
		.base = 0x6e000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_2,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 31),
	}, {
		.name = "pingpong_6", .id = PINGPONG_6,
		.base = 0x6f000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_3,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 20),
	}, {
		.name = "pingpong_7", .id = PINGPONG_7,
		.base = 0x70000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_3,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 21),
	}, {
		.name = "pingpong_cwb_0", .id = PINGPONG_CWB_0,
		.base = 0x66000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_4,
	}, {
		.name = "pingpong_cwb_1", .id = PINGPONG_CWB_1,
		.base = 0x66400, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_4,
	}, {
		.name = "pingpong_cwb_2", .id = PINGPONG_CWB_2,
		.base = 0x7e000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_5,
	}, {
		.name = "pingpong_cwb_3", .id = PINGPONG_CWB_3,
		.base = 0x7e400, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_5,
	},
};

static const struct dpu_merge_3d_cfg nord_merge_3d[] = {
	{
		.name = "merge_3d_0", .id = MERGE_3D_0,
		.base = 0x4e000, .len = 0x1c,
	}, {
		.name = "merge_3d_1", .id = MERGE_3D_1,
		.base = 0x4f000, .len = 0x1c,
	}, {
		.name = "merge_3d_2", .id = MERGE_3D_2,
		.base = 0x50000, .len = 0x1c,
	}, {
		.name = "merge_3d_3", .id = MERGE_3D_3,
		.base = 0x51000, .len = 0x1c,
	}, {
		.name = "merge_3d_4", .id = MERGE_3D_4,
		.base = 0x66700, .len = 0x1c,
	}, {
		.name = "merge_3d_5", .id = MERGE_3D_5,
		.base = 0x7e700, .len = 0x1c,
	},
};

/*
 * Each display compression engine (DCE) contains a dual hard-slice DSC
 * encoder pair, sharing a base address (same pattern as sm8750). Base
 * offsets are IPCAT-confirmed and address-identical to sm8750.
 */
static const struct dpu_dsc_cfg nord_dsc[] = {
	{
		.name = "dce_0_0", .id = DSC_0,
		.base = 0x80000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_0,
	}, {
		.name = "dce_0_1", .id = DSC_1,
		.base = 0x80000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_1,
	}, {
		.name = "dce_1_0", .id = DSC_2,
		.base = 0x81000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_0,
	}, {
		.name = "dce_1_1", .id = DSC_3,
		.base = 0x81000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_1,
	}, {
		.name = "dce_2_0", .id = DSC_4,
		.base = 0x82000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_0,
	}, {
		.name = "dce_2_1", .id = DSC_5,
		.base = 0x82000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_1,
	}, {
		.name = "dce_3_0", .id = DSC_6,
		.base = 0x83000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_0,
	}, {
		.name = "dce_3_1", .id = DSC_7,
		.base = 0x83000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_1,
	},
};

/*
 * wb_2 is IPCAT-confirmed address-identical to sm8750's WB_2 and reuses its
 * full field set. wb_1 has NO precedent anywhere else in this tree (grepped
 * exhaustively -- no other in-tree catalog populates a WB_1 entry); its
 * base/len/xin_id are IPCAT-confirmed but FIXME(display_bringup): the
 * remaining fields (.features/.format_list/.num_formats/.maxlinewidth/
 * .intr_wb_done) are left unset rather than guessed, since there is no
 * sibling-chip WB_1 entry to safely copy from.
 */
static const struct dpu_wb_cfg nord_wb[] = {
	{
		.name = "wb_1", .id = WB_1,
		.base = 0x64800, .len = 0x2c8,
		.xin_id = 7,
		/* FIXME(display_bringup): no in-tree WB_1 precedent -- features/format_list/maxlinewidth/intr_wb_done unresolved */
	}, {
		.name = "wb_2", .id = WB_2,
		.base = 0x65000, .len = 0x2c8,
		.features = WB_SDM845_MASK,
		.format_list = wb2_formats_rgb_yuv,
		.num_formats = ARRAY_SIZE(wb2_formats_rgb_yuv),
		.xin_id = 6,
		.maxlinewidth = 4096,
		.intr_wb_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 4),
	},
};

static const struct dpu_cwb_cfg nord_cwb[] = {
	{
		.name = "cwb_0", .id = CWB_0,
		.base = 0x66200, .len = 0x20,
	}, {
		.name = "cwb_1", .id = CWB_1,
		.base = 0x66600, .len = 0x20,
	}, {
		.name = "cwb_2", .id = CWB_2,
		.base = 0x7e200, .len = 0x20,
	}, {
		.name = "cwb_3", .id = CWB_3,
		.base = 0x7e600, .len = 0x20,
	},
};

/*
 * Only a sparse subset of the 11 physical INTF blocks is wired into the
 * catalog, matching the bring-up scope: DSI-associated INTF_1/INTF_2/INTF_5
 * are intentionally omitted (no DSI controllers on this chip). INTF_9/
 * INTF_10 required extending enum dpu_intf (see dpu_hw_mdss.h) since this
 * chip has more INTF blocks than any previously-supported chip.
 *
 * FIXME(display_bringup): intr_underrun/intr_vsync are IPCAT/HPG-confirmed
 * only for intf_6/intf_7/intf_8/intf_9/intf_10; intf_0/intf_3/intf_4 are
 * left without them (TBD). intr_tear_rd_ptr is TBD for all INTF entries
 * (not applicable to DP-type INTFs in the first place).
 */
static const struct dpu_intf_cfg nord_intf[] = {
	{
		.name = "intf_0", .id = INTF_0,
		.base = 0x34000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_0,
		.prog_fetch_lines_worst_case = 24,
	}, {
		.name = "intf_3", .id = INTF_3,
		.base = 0x37000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_0,	/* DP0 MST1, pairs with intf_0 */
		.prog_fetch_lines_worst_case = 24,
	}, {
		.name = "intf_4", .id = INTF_4,
		.base = 0x38000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_1,
		.prog_fetch_lines_worst_case = 24,
	}, {
		.name = "intf_6", .id = INTF_6,
		.base = 0x3a000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_0,	/* DP0 MST2 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 22),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 23),
	}, {
		.name = "intf_7", .id = INTF_7,
		.base = 0x3b000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_0,	/* DP0 MST3 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 0),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 1),
	}, {
		.name = "intf_8", .id = INTF_8,
		.base = 0x3c000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_1,	/* DP1 MST1 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 2),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 3),
	}, {
		.name = "intf_9", .id = INTF_9,
		.base = 0x3d000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_1,	/* DP1 MST2 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 4),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 5),
	}, {
		.name = "intf_10", .id = INTF_10,
		.base = 0x3e000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_1,	/* DP1 MST3 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 6),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 7),
	},
};

static const struct dpu_mdss_version nord_mdss_ver = {
	.core_major_ver = 12,
	.core_minor_ver = 1,
};

/* FIXME(display_bringup): perf/QoS data below is not chip-specific -- wholesale-reused from sm8750 (reference chip), not measured for nord */
const struct dpu_mdss_cfg dpu_nord_cfg = {
	.mdss_ver = &nord_mdss_ver,
	.caps = &nord_dpu_caps,
	.mdp = &nord_mdp,
	/* FIXME(display_bringup): .cdm left unset -- CDM version not derivable from IPCAT for this chip (MDP_CDM_0 register block is present, but no version-identifying field was found) */
	.ctl_count = ARRAY_SIZE(nord_ctl),
	.ctl = nord_ctl,
	.sspp_count = ARRAY_SIZE(nord_sspp),
	.sspp = nord_sspp,
	.mixer_count = ARRAY_SIZE(nord_lm),
	.mixer = nord_lm,
	.dspp_count = ARRAY_SIZE(nord_dspp),
	.dspp = nord_dspp,
	.pingpong_count = ARRAY_SIZE(nord_pp),
	.pingpong = nord_pp,
	.dsc_count = ARRAY_SIZE(nord_dsc),
	.dsc = nord_dsc,
	.merge_3d_count = ARRAY_SIZE(nord_merge_3d),
	.merge_3d = nord_merge_3d,
	.wb_count = ARRAY_SIZE(nord_wb),
	.wb = nord_wb,
	.cwb_count = ARRAY_SIZE(nord_cwb),
	.cwb = nord_cwb,
	.intf_count = ARRAY_SIZE(nord_intf),
	.intf = nord_intf,
	.vbif = &sm8650_vbif,
	.perf = &sm8750_perf_data,
};

#endif /* _DPU_12_1_NORD_H */
